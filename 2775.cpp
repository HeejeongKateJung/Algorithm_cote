#include <iostream>

using namespace std;

int T, k, n;

int apart[15][15];

int what(int k, int n) {
	
	//2호에서부터 n호까지 k층의 사람들 수를 구한다. 
	for(int f = 1; f <= k; f++){
	
		for(int i = 1; i <= n; i++){
			apart[f][i] = apart[f][i-1] + apart[f-1][i];
//			cout << f << "층의 " << i << "호: " <<  apart[f][i] << endl;
		}
	}
	return apart[k][n];
}

int main(void)
{
	cin >> T;
	
	for(int i = 1; i < 15; i++){
		apart[0][i] = i;
	}
	
	
	for(int i = 0; i < T; i++) {
		
		cin >> k >> n;
		
		int num = what(k, n);
		cout << num << endl;
	}
	return 0;
}
