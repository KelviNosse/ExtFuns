package com.extfuns;

public class CompareString {
    public String compare_str(String val1, String val2){
        if(val1.length() < val2.length()) return "-1";
        if(val1.length() > val2.length()) return "1";
        else return "0";
    }
}
