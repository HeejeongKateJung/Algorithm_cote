#include <iostream>

using namespace std;

int T, k, n;

int apart[15][15];

int what(int k, int n) {
	
	//2ȣ�������� nȣ���� k���� ����� ���� ���Ѵ�. 
	for(int f = 1; f <= k; f++){
	
		for(int i = 1; i <= n; i++){
			apart[f][i] = apart[f][i-1] + apart[f-1][i];
//			cout << f << "���� " << i << "ȣ: " <<  apart[f][i] << endl;
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
