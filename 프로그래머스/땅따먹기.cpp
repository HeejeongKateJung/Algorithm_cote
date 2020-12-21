#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxnum(int a, int b, int c){
    int max = a > b ? a : b;
    return max > c ? max : c;
}

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int dp[land.size()][4];
    for(int i = 0; i < 4; i++){
        dp[0][i] = land[0][i];
    }
    
    for(int i = 1; i < land.size(); i++){
        dp[i][0] = land[i][0] + maxnum(dp[i-1][1], dp[i-1][2], dp[i-1][3]);
        dp[i][1] = land[i][1] + maxnum(dp[i-1][0], dp[i-1][2], dp[i-1][3]);
        dp[i][2] = land[i][2] + maxnum(dp[i-1][0], dp[i-1][1], dp[i-1][3]);
        dp[i][3] = land[i][3] + maxnum(dp[i-1][0], dp[i-1][1], dp[i-1][2]);
        
    }
    
    int n = land.size();
    int max = maxnum(dp[n-1][0], dp[n-1][1], dp[n-1][2]);
    
    return max > dp[n-1][3] ? max : dp[n-1][3];
}
