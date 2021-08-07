package com.company;

import com.sun.org.apache.xpath.internal.operations.Bool;
import com.sun.tools.javac.util.Pair;
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

    int[][] map = new int[rows+1][columns+1];
    int num = 1;
    for (int i = 1; i <= rows; i++){
      for(int j = 1; j <= columns; j++) {
        map[i][j] = num;
        num++;
      }
    }


    for (int[] query : queries) {

      int x1 = query[0];
      int y1 = query[1];
      int x2 = query[2];
      int y2 = query[3];

      int temp = map[x1][y1];
      int min = rows*columns;
      // 왼쪽 세로 돌리기
      for (int i = x1+1; i <= x2; i++) {
        int tmp = map[i][y1];
        map[i - 1][y1] = tmp;
        min = Math.min(tmp, min);
      }
    }


   return answer;
  }

  private void printMap(int rows, int columns, int[][] map) {
    for (int i = 1; i <= rows; i++){
      for(int j = 1; j <= columns; j++) {
        System.out.print(map[i][j] + " ");
      }
      System.out.println();
    }
  }

  public int[] solution77486(String[] enroll, String[] referral, String[] seller, int[] amount) {
    int[] answer = new int[enroll.length];

    Map<String, String> refMap = new LinkedHashMap<>();
    Map<String, Integer> incomeMap = new LinkedHashMap<>();

    for (int i = 0; i < enroll.length; i++) {
      refMap.put(enroll[i], referral[i]);
      incomeMap.put(enroll[i], 0);
    }

    for (int i = 0; i < seller.length; i++) {
      String curSeller = seller[i];
      int curIncome = 100*amount[i];
      while (!curSeller.equals("-")) {
        int forParent = curIncome/10;
        int forMe = curIncome-forParent;
        incomeMap.put(curSeller, incomeMap.get(curSeller) + forMe);
        curIncome = forParent;
        curSeller = refMap.get(curSeller);

        if (curIncome < 1) break;
      }
    }

    for (int i = 0; i < enroll.length; i++) {
      answer[i] = incomeMap.get(enroll[i]);
    }

    return answer;
  }


}
