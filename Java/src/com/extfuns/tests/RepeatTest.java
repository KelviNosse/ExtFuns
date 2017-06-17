package com.extfuns.tests;

import com.extfuns.Repeat;
import org.testng.Assert;
import org.testng.annotations.Test;

public class RepeatTest {
    @Test
    public void testRepeat_string(){
        String result = new Repeat().repeat_string("kawaii", 3);
        Assert.assertEquals(result, "kawaiikawaiikawaii");
    }
}