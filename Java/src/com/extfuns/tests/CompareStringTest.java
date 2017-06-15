package com.extfuns.tests;

import com.extfuns.CompareString;
import org.testng.Assert;
import org.testng.annotations.Test;

public class CompareStringTest {
    CompareString cmpr = new CompareString();
    String s1 = "Doge";
    String s2 = "Doge";
    String s3 = "Shiba Inu";
    @Test
    public void testCompareStrLessThan() {
        String result = cmpr.compare_str(s3, s1);
        Assert.assertEquals(result, "-1");
    }

    @Test
    public void testCompareStrGreaterThan(){
        String result = cmpr.compare_str(s1, s3);
        Assert.assertEquals(result, "1");
    }

    @Test
    public void testCompareStrEqual(){
        String result = cmpr.compare_str(s1, s2);
        Assert.assertEquals(result, "0");
    }

}