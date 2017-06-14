package com.extfuns;
import java.io.IOException;
import java.net.InetSocketAddress;
import java.net.Socket;

public class Ping {

    public int ping(String address){
        //makes ping to an IPv4 address or hostname
        try {
            new Socket().connect(new InetSocketAddress(address, 80), 1000);
           return 1;
        } catch (IOException e) {
            return 0;
        }
    }

}
