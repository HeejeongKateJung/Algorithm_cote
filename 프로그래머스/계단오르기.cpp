#include <iostream>
#include <algorithm>
#include <cmath>


using namespace std;

int Max(int a, int b){
	return a > b ? a : b;
}

int main(void)
{
	int n;
	
	cin >> n;
	int arr[n];
	int sum[n];
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	sum[0] = arr[0];
	sum[1] = Max(arr[0] + arr[1], arr[1]);
	sum[2] = Max(arr[0] + arr[2], arr[1] + arr[2]);
	
	for(int i = 3; i < n; i++){
		sum[i] = Max(arr[i] + sum[i-2], arr[i] + arr[i-1] + sum[i-3]);
	}
	
	cout << sum[n-1] << endl;
	return 0;
}
