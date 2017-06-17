#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <setjmp.h>
#include <errno.h>
 
#define PACKET_SIZE 4096
#define MAX_WAIT_TIME   5
#define MAX_NO_PACKETS  2
 
 
char *addr[];
char sendpacket[PACKET_SIZE];
char recvpacket[PACKET_SIZE];
int sockfd,datalen = 56;
int nsend = 0, nreceived = 0;
double temp_rtt[MAX_NO_PACKETS];
double all_time = 0;
double min = 0;
double max = 0;
double avg = 0;
double mdev = 0;
 
struct sockaddr_in dest_addr;
struct sockaddr_in from;
struct timeval tvrecv;
pid_t pid;
 
void statistics(int sig);
void send_packet(void);
void recv_packet(void);
void computer_rtt(void);
void tv_sub(struct timeval *out,struct timeval *in);
int pack(int pack_no);
int unpack(char *buf,int len);
unsigned short cal_checksum(unsigned short *addr,int len);
 
void computer_rtt()
{
    double sum_avg = 0;
    int i;
    min = max = temp_rtt[0];
    avg = all_time/nreceived;
 
    for(i=0; i<nreceived; i++){
        if(temp_rtt[i] < min)
            min = temp_rtt[i];
        else if(temp_rtt[i] > max)
            max = temp_rtt[i];
 
        if((temp_rtt[i]-avg) < 0)
            sum_avg += avg - temp_rtt[i];
        else
            sum_avg += temp_rtt[i] - avg; 
        }
    mdev = sum_avg/nreceived;
}
 
void statistics(int sig)
{
    computer_rtt();
    close(sockfd);
    exit(1);
}
 
unsigned short cal_chksum(unsigned short *addr,int len)
{
    int nleft = len;
    int sum = 0;
    unsigned short *w = addr;
    unsigned short check_sum = 0;
 
    while(nleft>1)
    {
        sum += *w++;
        nleft -= 2;
    }
 
    if(nleft == 1)  
    {
        *(unsigned char *)(&check_sum) = *(unsigned char *)w;
        sum += check_sum;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    check_sum = ~sum;  
    return check_sum;
}
 
int pack(int pack_no)
{
    int i,packsize;
    struct icmp *icmp;
    struct timeval *tval;
    icmp = (struct icmp*)sendpacket;
    icmp->icmp_type = ICMP_ECHO; 
    icmp->icmp_code = 0;
    icmp->icmp_cksum = 0;
    icmp->icmp_seq = pack_no;
    icmp->icmp_id = pid;
 
    packsize = 8 + datalen;
    tval = (struct timeval *)icmp->icmp_data;
    gettimeofday(tval,NULL);
    icmp->icmp_cksum =  cal_chksum((unsigned short *)icmp,packsize); 
    return packsize;
}
 
void send_packet()
{
    int packetsize;
    if(nsend < MAX_NO_PACKETS)
    {
        nsend++;
        packetsize = pack(nsend);
        if(sendto(sockfd,sendpacket,packetsize,0,
            (struct sockaddr *)&dest_addr,sizeof(dest_addr)) < 0)
        {
            perror("sendto error");
        }
    }
 
}
 
 
void recv_packet()
{
    int n,fromlen;
    extern int error;
    fromlen = sizeof(from);
    if(nreceived < nsend)
    {   
    
        if((n = recvfrom(sockfd,recvpacket,sizeof(recvpacket),0,
            (struct sockaddr *)&from,&fromlen)) < 0)
        {
            perror("recvfrom error");
        }
        gettimeofday(&tvrecv,NULL);
        unpack(recvpacket,n);
        nreceived++;
    }
}
 
 
int unpack(char *buf,int len)
{
    int i;
    int iphdrlen;
    struct ip *ip;
    struct icmp *icmp;
    struct timeval *tvsend;
    double rtt;
 
 
    ip = (struct ip *)buf;
    iphdrlen = ip->ip_hl << 2;
    icmp = (struct icmp *)(buf + iphdrlen);
    len -= iphdrlen; 
    if(len < 8)  
    {
        return -1;
    }

    if((icmp->icmp_type == ICMP_ECHOREPLY) && (icmp->icmp_id == pid))
    {
        tvsend = (struct timeval *)icmp->icmp_data;
        tv_sub(&tvrecv,tvsend);
        rtt = tvrecv.tv_sec*1000 + tvrecv.tv_usec/1000;
        temp_rtt[nreceived] = rtt;
        all_time += rtt; 
    }
    else return -1;
}
 
 
void tv_sub(struct timeval *recvtime,struct timeval *sendtime)
{
    long sec = recvtime->tv_sec - sendtime->tv_sec;
    long usec = recvtime->tv_usec - sendtime->tv_usec;
    if(usec >= 0){
        recvtime->tv_sec = sec;
        recvtime->tv_usec = usec;
    }else{
        recvtime->tv_sec = sec - 1;
        recvtime->tv_usec = -usec;
    }
}
 
int ping(char* address)
{
    struct hostent *host;
    struct protoent *protocol;
    unsigned long inaddr = 0;
    int size = 50 * 1024;
    addr[0] = address;
    if((protocol = getprotobyname("icmp")) == NULL)
    {
        return -1;
    }
 
    if((sockfd = socket(AF_INET,SOCK_RAW,protocol->p_proto)) < 0)
    {
        return -1;
    }

    setuid(getuid());
 
    setsockopt(sockfd,SOL_SOCKET,SO_RCVBUF,&size,sizeof(size));
    bzero(&dest_addr,sizeof(dest_addr));
    dest_addr.sin_family = AF_INET; 
 
    if(inet_addr(address) == INADDR_NONE)
    {
        if((host = gethostbyname(address)) == NULL)
        {
            return -1;
        }
        memcpy((char *)&dest_addr.sin_addr,host->h_addr,host->h_length);
    }
    else{
        dest_addr.sin_addr.s_addr = inet_addr(address);
    }
    pid = getpid();

    signal(SIGINT,statistics);  
    while(nsend < MAX_NO_PACKETS){
        sleep(1);    
        send_packet();
        recv_packet();
    }
    return 1;
}
