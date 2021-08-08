package com.company;

import com.company.level2.Solution42888;
import com.company.level3.Solution49189;

public class Main {

    public static void main(String[] args) {
        KakaoMobility kakaoMobility = new KakaoMobility();

        String[] params = {
            "00-44   48 5555 836144",
            "00-44   48 5555 8361",
            "00-44   48 5555 83",
            "9898---",
            "3  - - - - 9",
            "456",
            "45678"
        };

        for (String p : params) kakaoMobility.task1(p);

    }
}
