package com.extfuns;

public class PMT {
    public double pmt(double interest_rate, int period_number, double loan_amount){
        return (loan_amount * (interest_rate/100)/12) / (1 - Math.pow(1 + ((interest_rate/100)/12), -period_number));
    }
}
