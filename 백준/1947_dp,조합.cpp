#include <iostream>
#define MOD 1000000000

using namespace std;

int main(void)
{
	long long N;
	cin >> N;
	long long dp[N+1];
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 2;
	
	for(int i = 4; i <= N; i++) {
		dp[i] = ((i-1)*(dp[i-1]+dp[i-2]))%MOD;
	}
	
	cout << dp[N];
	return 0;
}
