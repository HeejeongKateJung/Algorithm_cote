#include <iostream>

using namespace std;

int n, arr[1001], dp[1001];

int Min(int x, int y){
	
	return x < y ? x : y;
}

int main(void){
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		dp[i] = 1000;
	}
	
	dp[0] = 0;
	
	for(int i = 0; i < n; i++){
		
		//arr[i] == 0 �ϰ�� ������ �� �����Ƿ� �ǳʶ�. 
		if(arr[i] == 0){
			continue;
		}
		
		//arr[i + j] ������ �����Ҽ� �ִ�. 
		//�� j�� ���� ������. 
		for(int j = 1; j <= arr[i]; j++){
			
			dp[i+j] = Min(dp[i]+1, dp[i+j]);
					
			
		}
	}
	
	if(dp[n-1] == 1000){
		cout << -1;
		return 0;
	}
	
	cout << dp[n-1];
	
	return 0;
}
