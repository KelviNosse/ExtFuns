package com.extfuns.tests;

import com.extfuns.Temperature;
import org.testng.Assert;
import org.testng.annotations.Test;

public class TemperatureTest {
    Temperature temp = new Temperature();
    @Test
    public void testC2f(){
        double result = temp.c2f(25.0);
        Assert.assertEquals(result, 77.0);
    }

    @Test
    public void testF2c(){
        double result = temp.f2c(77.0);
        Assert.assertEquals(result, 25.0);
    }

}