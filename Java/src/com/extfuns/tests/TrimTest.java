package com.extfuns.tests;

import com.extfuns.Trim;
import org.testng.Assert;
import org.testng.annotations.Test;

public class TrimTest {
    @Test
    public void testTrim(){
        String result = new Trim().trim("xxxxxKawaiiDoge, I love hot dogsxxxx", "x");
        Assert.assertEquals(result, "KawaiiDoge, I love hot dogs");
    }

}