#include <iostream>
#include <algorithm>
using namespace std;

int n;
int t[16];
int p[16];
int dp[16];

int Max(int x, int y){
	return x > y ? x : y;
}

int main(void){
	
	int next;
	
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> t[i] >> p[i];
	}
	
	for(int i = n; i > 0; i--){
		next = i+t[i];
		
		if(next > n+1){
			dp[i] = dp[i+1];
		}
		else{
			
			//i��°�� ���� �ϴ� ���� ���ϴ� ��츦 ���Ѵ�. 
			dp[i] = Max(p[i]+dp[next], dp[i+1]);
		}
		
	}
	
//	for(int i = 1; i <= n; i++){
//		cout << dp[i] << " ";
//	}
	
	cout << dp[1];
	
	return 0;
}
