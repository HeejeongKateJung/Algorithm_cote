#include <iostream>
//#include <math>
using namespace std;

int n;

//0: R / 1: G / 2: B
int arr[1001][1001];
int sum[1001][1001];

int Min(int a, int b)
{
	if(a < b){
		return a;
	}else{
		return b;
	}
}

int main(void)
{
	cin >> n;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	
	sum[1][0] = arr[1][0];
	sum[1][1] = arr[1][1];
	sum[1][2] = arr[1][2];
	
	for(int i = 2; i <= n; i++){
		sum[i][0] = Min(arr[i][0] + sum[i-1][1], arr[i][0] + sum[i-1][2]);
		sum[i][1] = Min(arr[i][1] + sum[i-1][0], arr[i][1] + sum[i-1][2]);
		sum[i][2] = Min(arr[i][2] + sum[i-1][0], arr[i][2] + sum[i-1][1]);
	}
	
	int min = sum[n][0];
	for(int i = 0; i < 3; i++){
		if(min > sum[n][i]){
			min = sum[n][i];
		}
	}
	
	cout << min;
	
}
