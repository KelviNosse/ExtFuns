package com.extfuns.tests;

import com.extfuns.PMT;
import org.testng.Assert;
import org.testng.annotations.Test;


public class PMTTest {
    @Test
    public void testPmt(){
        double interest_rate = 6.50;
        int period_number = 48;
        double loan_amount = 15000;
        double pmt = new PMT().pmt(interest_rate, period_number, loan_amount);
        Assert.assertEquals(Math.round(pmt * 100.0)/100.0, 355.72);
    }

}