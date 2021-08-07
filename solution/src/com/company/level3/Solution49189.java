package com.company.level3;

import java.util.HashMap;
import java.util.Map;
import java.util.Queue;
import java.util.concurrent.ConcurrentLinkedQueue;

public class Solution49189 {

  private class Node {
    int bottom;
    int up;
  }
  public int solution49191(int n, int[][] results) {
    int answer = 0;

    boolean[][] info = new boolean[n + 1][n + 1];

    for (int i = 1; i <= n; i++) {
      info[i][i] = false;
    }

    // info[이긴사람][진사람] = true;
    for (int[] result : results) {
      info[result[0]][result[1]] = true;
    }

    // info[a][b] && info[b][c] == info[a][c]
    for (int k = 1; k <= n; k++){
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          if (info[i][k] && info[k][j]) {
            info[i][j] = true;
          }
        }
      }
    }

    // 이겼거나 졌다면  count 를 샌다.
    for (int i = 1; i <= n; i++) {
      int count = 0;
      for (int j = 1; j <= n; j++) {
        if (info[i][j] || info[j][i]) count++;
        if (count == n-1) answer++;
      }
    }

    return answer;
  }

  public int solution49189(int n, int[][] edge) {
    int answer = 0;
    Queue<Integer> q = new ConcurrentLinkedQueue<>();

    boolean[][] info = new boolean[n+1][n+1];
    int[] count = new int[n+1];

    for(int[] ed : edge) {
      info[ed[0]][ed[1]] = info[ed[1]][ed[0]] = true;
    }
    q.add(1);

    int maxCount = 0;
    while (!q.isEmpty()) {
      int node = q.poll();

      for (int i = 2; i <= n; i++) {
        if (count[i] == 0 && info[node][i]) {
          count[i] = count[node]+1;
          q.add(i);
          maxCount = Math.max(maxCount, count[i]);
        }
      }
    }

    for (int c : count) {
      if (c == maxCount) answer++;
    }

    return answer;

  }

}
