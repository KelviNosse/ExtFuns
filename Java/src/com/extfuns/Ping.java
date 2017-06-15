package com.extfuns;
import java.io.IOException;
import java.net.InetSocketAddress;
import java.net.Socket;

public class Ping {

    public static void main(String[] args){
        System.out.println((new Numerics()).dec2hex(51966));
    }

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
