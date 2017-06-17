package com.extfuns;

public class Trim {
    public String trim(String stringValue, String stringToRemove )
    {
        String answer = stringValue;
        while(answer.startsWith(stringToRemove))
            answer = answer.substring(stringToRemove.length());

        while(answer.endsWith(stringToRemove))
            answer = answer.substring( 0, answer.length() - stringToRemove.length());

        return answer;
    }
}
