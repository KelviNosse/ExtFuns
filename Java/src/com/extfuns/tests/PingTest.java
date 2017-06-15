package com.extfuns.tests;

import com.extfuns.Ping;
import org.testng.Assert;
import org.testng.annotations.Test;

public class PingTest {
    @Test
    public void testPingHostName(){
        String address = "www.google.com";
        int status = new Ping().ping(address);
        Assert.assertEquals(status, 1);
    }

    @Test
    public void testPingIPv4Address(){
        String ip_address = "192.30.253.113";
        int status = new Ping().ping(ip_address);
        Assert.assertEquals(status, 1);
    }

}