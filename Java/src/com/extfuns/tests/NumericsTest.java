package com.extfuns.tests;

import com.extfuns.Numerics;
import org.testng.Assert;
import org.testng.annotations.Test;

public class NumericsTest {
    Numerics nums = new Numerics();
    @Test
    public void testDec2hex(){
        String hexString = nums.dec2hex(48879);
        Assert.assertEquals(hexString, "BEEF");
    }

    @Test
    public void testHex2dec(){
        int decimal_value = nums.hex2dec("BEEF");
        Assert.assertEquals(decimal_value, 48879);
    }

    @Test
    public void testFactorial(){
        int result = nums.factorial(9);
        Assert.assertEquals(result, 362880);
    }

    @Test
    public void testBin2dec(){
        int decimal_value = nums.bin2dec("10110");
        Assert.assertEquals(decimal_value, 22);
    }

    @Test
    public void testDec2bin(){
        String binaryString = nums.dec2bin(22);
        Assert.assertEquals(binaryString, "10110");
    }

}