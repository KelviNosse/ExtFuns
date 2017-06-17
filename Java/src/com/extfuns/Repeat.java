package com.extfuns;

import java.util.Collections;

public class Repeat {
    public String repeat_string(String value, int times){
        return String.join("", Collections.nCopies(times, value));
    }
}
