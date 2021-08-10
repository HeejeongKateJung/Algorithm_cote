package com.company.codility;

import java.util.Arrays;

public class CodilityMayOf4th {
    public int solution(int[] A, int L, int R) {
        // write your code in Java SE 8

        /** 문제 설명
         * A = [1,4,5,5]
         *
         *
         * */
        Arrays.sort(A);

        int N = A.length;

        int answer = 0;
        boolean[] visit = new boolean[N];

        for (int i = 0; i < N; i++) {
            if (visit[i]) continue;
            if (R < A[i]) {
                System.out.println("R: " + R + " A[i]: " + A[i]);
                answer++;
                R = A[i];
                visit[i] = true;
            }
        }

        System.out.println("answer: " + answer);

        for (int i = N-1; i >= 0; i--) {
            if (visit[i]) continue;
            if (L > A[i]) {
                System.out.println("L: " + L + " A[i]: " + A[i]);
                answer++;
                L = A[i];
                visit[i] = true;
            }
        }

        System.out.println("answer: " + answer);

        return answer;
    }

}
