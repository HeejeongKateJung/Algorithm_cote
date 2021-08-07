package com.company;

import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class Kakao2021 {
  public int solution72413(int n, int s, int a, int b, int[][] fares) {
    int[][] costMap = new int[n+1][n+1];

    // 간선이 없을 경우 가중치를 최대로 준다.
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        costMap[i][j] = 999999;
      }
    }

    // 자기한테 가는 비용은 0이다.
    for (int i = 1; i <= n; i++) {
      costMap[i][i] = 0;
    }

    // costMap 으로 초기화 해준다.
    for (int[] fare : fares) {
      costMap[fare[0]][fare[1]] = fare[2];
      costMap[fare[1]][fare[0]] = fare[2];
    }

    // 모든 노드에 대한 최단거리를 구한다.
    for (int pass = 1; pass <= n; pass++) {
      for (int start = 1; start <= n; start++) {
        for (int end = 1; end <= n; end++) {
          if (costMap[start][pass] + costMap[pass][end] < costMap[start][end]) {
            costMap[start][end] = costMap[start][pass] + costMap[pass][end];
          }
        }
      }
    }

    // start -> 어딘지 모를 합승 도착 지점 + 합승도착 지점 -> A + 합승도착 지점 -> B 의 최솟값이 정답이다.
    int answer = costMap[s][a] + costMap[s][b];

    for (int pass = 1; pass <= n; pass++) {
      answer = Math.min(answer, costMap[s][pass] + costMap[pass][a] + costMap[pass][b]);
    }
    return answer;
  }

//  private Map<String, Integer> infoMap;

//  public int[] solution72412(String[] info, String[] query) {
//
//    // 1. 주어진 info 에 대해서 조건에 '-'를 추가한 모든 경우의 수를 구해준다.
//    // 예를들어 java backend junior pizza 150 인 경우
//    // - backend junior pizza 150
//    // java - junior pizza 150
//    // 뭐 이런 식이다.
//    infoMap = new HashMap<>();
//    for (String infoString : info) {
//      String[] conditions = infoString.split(" ");
//
//    }
//
//  }

  // "-" 를 포함한 모든 경우의 수를 반
//  private void combination(String[] conditions, String depth, String str) {
//    if (depth == 4) {
//      if (!infoMap.containsKey(str)) {
//        infoMap.put(str, Integer.parseInt(conditions[4]));
//        return;
//      }
//
//      combination(conditions, depth+1, str);
//
//    }
//  }
}
