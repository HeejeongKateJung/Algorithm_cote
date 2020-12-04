#include <iostream>
using namespace std;


int n, arr[2001], m, S[1000001], E[1000001];
int s, e, answer[1000001];
int dp[2001][2001];

int main(void)
{
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	
	cin >> m;
	
	for(int i = 1; i <= m; i++){
		cin >> S[i] >> E[i];
		
	}
	
	for(int i = 1; i <= n; i++){
		//s, e 두 수가 같은경우 무조건 팰린드롬 
		dp[i][i] = 1;
	}
	
	//길이별로 증가해야 한다. 
	//i == 1 -> 길이는 2 
	for(int i = 1; i <= n-1; i++){
		
			
		for(int j = 1; j <= n-i; j++){
			
			//처음과 끝이 같은지. 그리고 그 사이의 것이 팰린드롬인지 확인 
			if(arr[j] == arr[j+i] && dp[j+1][j+i-1] == 1){
				dp[j][j+i] = dp[j+i][j] = 1;
			}
		}
	}


	
	for(int i = 1; i <= m; i++){
		cout << dp[S[i]][E[i]] << endl;
		
	}
	
	return 0;
}



//Dynamic Programming 을 쓰지 않았을 때 시간 초과가 나는 Solution		
//		for(int j = 0; j < n; j++){
//			
//			//탈출조건이자 팰린드롬인 조건 
//			if((tempE-j)-(tempS+j) < 2){
//				cout << 1 << endl;
//				break;
//			}
//			
//			//팰린드롬이 아닌 조건 
//			if(arr[tempS+j] != arr[tempE-j]){
//				cout << 0 << endl;
//				break;
//			}
//			
//		}
