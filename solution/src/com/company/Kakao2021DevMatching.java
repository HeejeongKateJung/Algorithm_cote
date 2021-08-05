package com.company;

import com.sun.org.apache.xpath.internal.operations.Bool;
import java.util.LinkedHashMap;
import java.util.Map;

public class Kakao2021DevMatching {

  public int[] solution77484(int[] lottos, int[] win_nums) {
    Map<Integer, Boolean> map = new LinkedHashMap<>();
    int match = 0;
    int zero = 0;


    for (int win_num : win_nums) {
      map.put(win_num, true);
    }

    for (int lotto: lottos) {
      if (lotto == 0) zero++;
      if (map.containsKey(lotto)) match++;
    }
    int[] answer = new int[2];

    answer[0] = 7-(match+zero);
    answer[1] = Math.min(6, 7-match);

    return answer;
  }

  public int[] solution77485(int rows, int columns, int[][] queries) {
    int[] answer = {};
    

    return answer;
  }

}
