package com.extfuns;

public class Numerics {
    public String dec2hex(int decimal_value){
        return Integer.toHexString(decimal_value);
    }
    public int hex2dec(String hex_value){
        return Integer.parseInt(hex_value, 16);
    }
    public int factorial(int number){
        if(number == 0) return 1;
        return number * factorial(number - 1);
    }
    public int bin2dec(String binaryNumber){
        return Integer.parseInt(binaryNumber, 2);
    }
    public String dec2bin(int number){
        return Integer.toBinaryString(number);
    }
}
