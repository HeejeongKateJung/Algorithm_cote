#include <iostream>

using namespace std;

int N, M;
int table[301][21];

//dp[N][M] : N 원을 M번째 기업까지 투자했을 때 나올 수 있는 최대 이익 
int dp[301][21];	//최대가 나오는 조합을 기록한 dp 
					//각 index 당 투가 수익금의 최댓 값 
int ratio[301][21];

int Max(int x, int y){
	return x > y ? x : y;
}



int main(void)
{
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++){
		int p;
		cin >> p;
		for(int j = 1; j <= M; j++){
			
			cin >> table[i][j];
		}
	}
	
	
	//돈을 1만원씩 늘려간다. 
	for(int i = 1; i <= N; i++){
		
		//모든 기업에 대해서 차례대로 
		for(int j = 1; j <= M; j++){
			
			dp[i][j] = dp[i][j-1];
			if(dp[i][j] < table[i][j]){
				dp[i][j] = table[i][j];
				
			}
			dp[i][j] = Max(dp[i][j-1], table[i][j]);
			for(int k = 1; k < i; k++){
				
				/** 예를들어 3만원이 총 투자 금액일 경우
				내가 c 기업까지 3만원 총 투자할때 최대 금액을 구하려고 하면,
				기업 b '까지' 1만원 투자 최대 금액+c기업 2만원 투자
						vs
				기업 b '까지' 2만원 투자 최대금액 + c기업 1만원 투자
				를 비교해야 한다. 이를 일반식으로 나타내면 이렇게 된다.*/ 
				
				if(dp[i][j] < dp[k][j-1] + table[i-k][j]){
					dp[i][j] = dp[k][j-1] + table[i-k][j];
				}
				
//				dp[i][j] = Max(dp[i][j], dp[k][j-1] + table[i-k][j]);
			}
		}
	}
	
//	cout << endl;
//	
//	for(int i = 1; i <= N; i++){
//		for(int j = 1; j <= M; j++){
//			cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}
//	
//	cout << endl;
//	for(int i = 1; i <= N; i++){
//		for(int j = 1; j <= M; j++){
//			cout << ratio[i][j] << " ";
//		}
//		cout << endl;
//	}

	cout << dp[N][M];
	
	
	
	
	
	return 0;
}
