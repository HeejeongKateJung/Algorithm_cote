#include <iostream>
#include <algorithm>
using namespace std;


int n, big;
int arr[1001];
int dp[1001];

int main(void){
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	dp[0] = 1;
	
	for(int i = 1; i < n; i++){
		
		dp[i] = 1;
		for(int j = 0; j < i; j++){
			
			//조건1: 나보다 작은 수중에 
			//조건2: dp의 최댓값을 찾아 +1 해준다. 
			if(arr[j] < arr[i] && dp[i] < dp[j]+1){
				dp[i] = dp[j]+1;
			}
		}
	}
	
	sort(dp, dp+n);
	cout << dp[n-1];
	
	return 0;
}


//int main(void){
//	
//	cin >> n;
//	
//	for(int i = 0; i < n; i++){
//		cin >> arr[i];
//	}
//	
//	if(n == 1){
//		cout << 1;
//		return 0;
//	}
//	
//	//초기화
//	dp[0] = 1;
//	big = dp[0];
//	
//	for(int i = 1; i < n; i++){
//		
//		dp[i] = 1;
//		for(int j = 0; j <= i; j++){
//			
//			if(arr[j] < arr[i] && dp[j] < big){
//				dp[i] = dp[j]+1;
//			}
//			
//			if(arr[j] < arr[i] && dp[j] == big){
//				dp[i] = dp[j]+1;
//				big = dp[i];
////				for(int k = 0; k < n; k++){
////					cout << dp[k] << " ";
////				}
////				
////				cout << endl;
//				break;
//			}
//		}
//	}
//	
//	for(int i = 0; i < n; i++){
//		cout << dp[i] << " ";
//	}
//
//	sort(dp, dp+n);
//	
////	for(int i = 0; i < n; i++){
////		cout << dp[i] << " ";
////	}
//	
////	cout << dp[n-1];
//	
//	return 0;
//}
