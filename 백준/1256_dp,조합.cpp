#include <iostream>
#include <string>
using namespace std;

int N, M, K;
string ans = "";
//dp[N+M][M] : N+M���� �ڸ��߿� M���� �����ϴ� ����� �� 
int dp[201][201];

//��ǻ� N+M���� �ڸ��߿� M���� �����ϴ� ����� ���� ���Ѵ�.
//������ �ڸ����� a�� ä�������� �Ǳ� �����̴�. 


int main(void)
{
	cin >> N >> M >> K;
	
	dp[0][0] = 1;
	for(int i = 1; i <= N+M; i++){
		dp[i][0] = 1;
		//j < i : ���� ���� ��ü �ڸ����� ������ �۴�.
		// N >= 1 , M >= 1 �̱� �����̴�. 
		for(int j = 1; j < i && j <= M; j++){
			dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
			
			if(dp[i][j] > 1000000000) dp[i][j] = 1000000000;
		}
		dp[i][i] = 1;
	}
	
//	K--;
	
	if(dp[N+M][M] < K){
		cout << "-1" << endl;
		return 0;
	}
	
	
	for(int i = N+M-1; i >= 0; i--) {
		
//		cout << "dp[i][M]: " << dp[i][M] << endl;
		if(i >= M && dp[i][M] > K){
			ans+='a';
		}else{
			ans+='z';
			K-=dp[i][M];
			M--;
		}
	}
	cout << ans << endl;
	return 0;
}
