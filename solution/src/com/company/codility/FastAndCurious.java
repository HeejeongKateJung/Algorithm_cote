package com.company.codility;

public class FastAndCurious {

    public int solution(int[] A) {
        int N = A.length;
        int totalCost = 0;
        for (int i = 1; i < N; i++) {
            totalCost += A[N-1] - A[i];
        }

        int minCost = totalCost;

        for (int i = 0; i < N-1; i++) {
            // 줄어드는 비용: 다음 구간에서 끝까지 가는 비용
            totalCost -= A[N-1] - A[i+1];
            // 늘어나는 비용: 현재까지 거쳐왔던 구간 * 지금 도시에서 다음 도시로 가는 비용
            totalCost += (i+1) * (A[i+1]-A[i]);
            minCost = Math.min(minCost, totalCost);
        }
        return minCost;
    }
}
