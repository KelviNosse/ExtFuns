package com.extfuns;

public class Temperature {
    public double c2f(double celsius){
        return celsius * 1.8 + 32;
    }
    public double f2c(double fahrenheit){
        return (fahrenheit - 32)/1.8;
    }
}
