#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int factorial(int *number){
    int i, fact = 1;
    for(i = 1; i <= *number; i++)
        fact = fact * i;
    return fact;
}

double pmt(double *interest_rate, int *period_number, double *loan_amout){
    double N = (*loan_amout)*((*interest_rate)/100)/12;
    double D = 1 - pow(1 + (((*interest_rate)/100)/12), (*period_number)*-1);
    return N/D;
}

int bin2dec(int *num){
    int decimalNumber = 0, i = 0, remainder;
    while ((*num) !=0)
    {
        remainder = (*num) %10;
        (*num) /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    return decimalNumber;
}

int dec2bin(int *num){
    int binary = 0, i = 1, remainder;
    while((*num) != 0){
        remainder = (*num) % 2;
        (*num) = (*num)/2;
        binary = binary + (remainder*i);
        i = i*10;
    }
    return binary;
}

double c2f(double *celsius){
    return (*celsius) * 1.8 + 32;
}

double f2c(double *fahrenheit){
    return ((*fahrenheit) - 32) / 1.8;
}

int hex2dec(const char *input){
    int number = 0;
    while(*input){
        number *= 16;
        const char c = *input;
        char A = 'A';
        char a = 'a';
        char O = '0';
        if( c>='A' && c<='F' ) number += c-(int)A+10;
        if( c>='a' && c<='f' ) number += c-(int)a+10;
        if( c>='0' && c<='9' ) number += c-(int)O;
        input++;
    }
    return number;
}

char* dec2hex(int *number){
    int remainder,quotient;
	int i=1,j,temp,x;
	char hexadecimalNumber[25];
	quotient = *number;
	while(quotient!=0) {
		temp = quotient % 16;
		if(temp < 10)
	        temp =temp + 48; 
        else
		    temp = temp + 55;
		hexadecimalNumber[i++]= temp;
		quotient = quotient / 16;
	}
    char* result = (char*)malloc(25 + 1 * sizeof(char));
    for(x = 0; x < 25; x++) result[x] = '\0';
    result[25] = '\0';
    int k = 0;
    for(j = i - 1; j > 0; j--){
        result[k] = hexadecimalNumber[j]; 
        k++;
    }
    return result;
}

int compare_string(const char* str1, const char* str2){
    while(*str1 && (*str1 == *str2)){
        str1++;
        str2++;
    }
    int diff = *(const unsigned char*)str1 - *(const unsigned char*)str2;
    if(diff < 0) return -1;
    else if(diff > 0) return 1;
    else return 0;
}

char * trim(char * s, char *val) {
    int l = strlen(s);

    while(s[l - 1] == *val) --l;
    while(* s && * s == *val) ++s, --l;

    return strndup(s, l);
}

char *repeat(const char* s, int *x){
    int i, count = 0;

    while(s[count] != '\0'){
        ++count;
    }

    char *result = malloc(count * (*x) + 1);
    if(result){
        char *na = result;
        for(i = 0; i < *x; ++i) {
            const char *p=s;
            while(*p)
                *na++ = *p++;
        }
        *na = '\0';
    }
    return result;
}