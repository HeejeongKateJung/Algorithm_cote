#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void)
{
	int n;
	
	cin >> n;
	
	int arr[n][n];
	int sum[n][n];
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i; j++){
			
			cin >> arr[i][j];
			
		}
	}
	
	sum[0][0] = arr[0][0];
	
	for(int i = 1; i < n; i++){
		for(int j = 0; j <= i; j++){
			if(j == 0){
				sum[i][j] = sum[i-1][j] + arr[i][j];
			}
			else if(j == i){
				sum[i][j] = sum[i-1][j-1] + arr[i][j];
			}
			else{
				sum[i][j] = max(sum[i-1][j-1], sum[i-1][j]) + arr[i][j];
			}
		}
	}
	
	sort(sum[n-1], sum[n-1]+n);
	cout << sum[n-1][n-1];
	
	return 0;
}
