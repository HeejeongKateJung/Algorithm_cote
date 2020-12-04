#include <iostream>
using namespace std;


int n, arr[2001], m, S[1000001], E[1000001];
int s, e, answer[1000001];
int dp[2001][2001];

int main(void)
{
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	
	cin >> m;
	
	for(int i = 1; i <= m; i++){
		cin >> S[i] >> E[i];
		
	}
	
	for(int i = 1; i <= n; i++){
		//s, e �� ���� ������� ������ �Ӹ���� 
		dp[i][i] = 1;
	}
	
	//���̺��� �����ؾ� �Ѵ�. 
	//i == 1 -> ���̴� 2 
	for(int i = 1; i <= n-1; i++){
		
			
		for(int j = 1; j <= n-i; j++){
			
			//ó���� ���� ������. �׸��� �� ������ ���� �Ӹ�������� Ȯ�� 
			if(arr[j] == arr[j+i] && dp[j+1][j+i-1] == 1){
				dp[j][j+i] = dp[j+i][j] = 1;
			}
		}
	}


	
	for(int i = 1; i <= m; i++){
		cout << dp[S[i]][E[i]] << endl;
		
	}
	
	return 0;
}



//Dynamic Programming �� ���� �ʾ��� �� �ð� �ʰ��� ���� Solution		
//		for(int j = 0; j < n; j++){
//			
//			//Ż���������� �Ӹ������ ���� 
//			if((tempE-j)-(tempS+j) < 2){
//				cout << 1 << endl;
//				break;
//			}
//			
//			//�Ӹ������ �ƴ� ���� 
//			if(arr[tempS+j] != arr[tempE-j]){
//				cout << 0 << endl;
//				break;
//			}
//			
//		}
