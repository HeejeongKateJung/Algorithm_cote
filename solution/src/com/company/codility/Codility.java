package com.company.codility;

public class Codility {

    public int getValidCount(String s) {
        int left = 0;
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(') left++;
            if (c == ')') {
                if (left > 0) {
                    left--;
                    count++;
                }
            }
        }
        return count;
    }

    protected int answer = 0;
    protected boolean[] visit;
    protected String origin;

    public String flip() {
        String result = "";
        for (int i = 0; i < visit.length; i++) {
            if (visit[i]){
                if (origin.charAt(i) == '('){
                    result+=")";
                } else {
                    result+="(";
                }
            }
            else {
                result+=origin.charAt(i);
            }
        }
        return result;
    }

    public void print() {
        for (boolean v : visit) {
            System.out.print(v + " ");
        }
        System.out.println();
    }
    public void pick(String str, int idx, int count, int k) {
        answer = Math.max(answer, getValidCount(str));

        if (count == k){
            System.out.println("count is " + k + ", returned");
            return;
        }

        for (int i = idx; i < str.length(); i++) {
            visit[i] = true;
            pick(flip(), i+1, count+1, k);
            visit[i] = false;
        }
    }

    public int solution(String S, int K) {

        origin = S;
        visit = new boolean[S.length()];

        pick(S, 0, 0, K);
        System.out.println("answer: " + answer);
        return answer*2;
    }

}
