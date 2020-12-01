#include <iostream>
#define MOD 1000000000
using namespace std;
int N, K;

//dp[K][N] -> K개의 원소로 N만들 
long long dp[201][201];

int main(void) {
	cin >> N >> K;
	
	//1개의 원소를 사용해서 N을 만드는 방법은 1개뿐.
	for(int i = 0; i <= N; i++){
		dp[1][i] = 1;
	}
	
	
	for(int i = 2; i <= K; i++){
		for(int j = 0; j <= N; j++) {
			for(int k = 0; k <= j; k++){
				dp[i][j] += dp[i-1][k];
			}
			dp[i][j] = dp[i][j] % MOD;
		}
	}
	
	cout << dp[K][N] << endl;
	return 0;
}
