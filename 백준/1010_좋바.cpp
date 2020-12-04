#include <iostream>

using namespace std;

//int n, k, choice, T, count;
//void comb(int number, int idx, int choice) {
//	cout << "number: " << number << " idx: " << idx << " choice: " << choice << endl;
//	if(idx > k) {
//		count++;
//		return;
//	}
//	
//	if(number > n) return;
//	
////	cout << "number: " << number << " idx: " << idx << " choice: " << choice << endl;
//	
//	//현재 요소를 선택함.
//	comb(number+1, idx+1, choice+1);
//	//현재 요소 선택 안함. 
//	comb(number+1, idx, choice);
//	 
//	
//	
//} 

int dp[31][31], T;
int main(void) {
	
	cin >> T;
	for(int i = 0; i < T; i++) {
		int N, M;
		cin >> N >> M;
		
		for(int i = 1; i <= M; i++){
			dp[1][i] = i;
		}
		
		for(int i = 2; i <= N; i++) {
			for(int j = 2; j <= M; j++) {
				dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
			}
		}
		
		cout << dp[N][M] << endl;
		
	}
	
	return 0;
}
