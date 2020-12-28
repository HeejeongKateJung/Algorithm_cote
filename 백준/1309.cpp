#include <iostream>
#include <algorithm>
using namespace std;
#define N_MAX 100000 + 1 
#define DIV 9901
 
int main() {
    ios::sync_with_stdio(false);
 
    int N;
    // 0�� �ε����� ���� 
    // 0 -> ���� ���� ĭ�� ���ڰ� �־���
    // 1 -> ���� �Ʒ� ĭ�� ���ڰ� �־���
    // 2 -> ���� ĭ���� ���ڰ� ������ 
    int cage_dp[3][N_MAX] = { 0 };
    cin >> N;
 
    cage_dp[0][1] = 1;
    cage_dp[1][1] = 1;
    cage_dp[2][1] = 1;
 
    for (int n_idx = 2; n_idx <= N; n_idx++) {
        cage_dp[0][n_idx] = (cage_dp[1][n_idx - 1] + cage_dp[2][n_idx - 1])%DIV;
        cage_dp[1][n_idx] = (cage_dp[0][n_idx - 1] + cage_dp[2][n_idx - 1])%DIV;
        cage_dp[2][n_idx] = (cage_dp[0][n_idx - 1] + cage_dp[1][n_idx - 1] + cage_dp[2][n_idx - 1])%DIV;
    }
 
    cout << (cage_dp[0][N] + cage_dp[1][N] + cage_dp[2][N]) % DIV;
 
    return 0;
}

