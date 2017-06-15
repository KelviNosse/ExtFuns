package com.extfuns;

public class CompareString {
    public String compare_str(String val1, String val2){
        if(val1.compareTo(val2) < 0) return "1";
        else if(val1.compareTo(val2) > 0) return "-1";
        else return String.valueOf(val1.compareTo(val2));
    }
}
