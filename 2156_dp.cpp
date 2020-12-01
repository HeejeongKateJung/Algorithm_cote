#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[10001], dp[10001];


int Max(int a, int b){
	if(a > b){
		return a;
	}else{
		return b;
	}
}

int Min(int a, int b){
	if(a < b){
		return a;
	}else{
		return b;
	}
}

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	if(n == 1){
		cout << arr[0];
		return 0;
	}if(n == 2){
		cout << arr[0]+arr[1];
		return 0;
	}
	
	dp[0] = arr[0];
	dp[1] = arr[0]+arr[1];
	dp[2] = Max(Max(arr[0]+arr[1], arr[0]+arr[2]), arr[1]+arr[2]);
	if(n == 3){
		cout << dp[2];
		return 0;
	}
	
	for(int i = 3; i < n; i++){
		dp[i] = Max(Max(dp[i-3]+arr[i-1]+arr[i], dp[i-2] + arr[i]), dp[i-1]);
	}
	
	cout << dp[n-1];
	
	return 0;
}


//if(n == 1){
//		cout << arr[0];
//		return 0;
//	}
//	if(n == 2){
//		cout << arr[0]+arr[1];
//		return 0;
//	}if(n == 3){
//		temp[0] = arr[0]+arr[1];
//		temp[1] = arr[0]+arr[2];
//		temp[2] = arr[1]+arr[2];
//		sort(temp, temp+n);
//		cout << temp[n-1];
//		return 0;
//	}
//	
//	//3번째 수까지 초기화
//	dpmax[0] = arr[0];
//	dpmax[1] = arr[0]+arr[1];
//	dpmin[1] = arr[0]+arr[1];
//	
////	temp[0] = arr[0]+arr[1];
////	temp[1] = arr[0]+arr[2];
////	temp[2] = arr[1]+arr[2];
////	
////	for(int i = 0; i < 3; i++){
////		cout << temp[i] << " ";
////	}
////	cout << endl;
////	
////	sort(temp, temp+3);
////	
////	for(int i = 0; i < 3; i++){
////		cout << temp[i] << " ";
////	}
////	cout << endl;
//	
//	dpmax[2] = Max(arr[0]+arr[2], arr[1]+arr[2]);
//	dpmin[2] = Min(arr[0]+arr[2], arr[1]+arr[2]);
//	
//	
//	//i-1번째의 min+arr[i] 와 i-2번째 max+arr[i]를 비교하여 큰것이 i의 max이다.
//	for(int i = 3; i < n; i++){
//		dpmax[i] = Max(dpmin[i-1]+arr[i], dpmax[i-2]+arr[i]);
//		dpmin[i] = Min(dpmin[i-1]+arr[i], dpmax[i-2]+arr[i]);
//	}
//	
//	
//	
//	for(int i = 0; i < n; i++){
//		
//		cout << dpmax[i] << " ";
//	}
//	cout << endl;
//	for(int i = 0; i < n; i++){
//		
//		cout << dpmin[i] << " ";
//	}
//	
////	sort(dpmax, dpmax+n);
////	cout << dpmax[n-1] << endl;
//	
//	
