#include <iostream>

using namespace std;

int N, M;
int table[301][21];

//dp[N][M] : N ���� M��° ������� �������� �� ���� �� �ִ� �ִ� ���� 
int dp[301][21];	//�ִ밡 ������ ������ ����� dp 
					//�� index �� ���� ���ͱ��� �ִ� �� 
int ratio[301][21];

int Max(int x, int y){
	return x > y ? x : y;
}



int main(void)
{
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++){
		int p;
		cin >> p;
		for(int j = 1; j <= M; j++){
			
			cin >> table[i][j];
		}
	}
	
	
	//���� 1������ �÷�����. 
	for(int i = 1; i <= N; i++){
		
		//��� ����� ���ؼ� ���ʴ�� 
		for(int j = 1; j <= M; j++){
			
			dp[i][j] = dp[i][j-1];
			if(dp[i][j] < table[i][j]){
				dp[i][j] = table[i][j];
				
			}
			dp[i][j] = Max(dp[i][j-1], table[i][j]);
			for(int k = 1; k < i; k++){
				
				/** ������� 3������ �� ���� �ݾ��� ���
				���� c ������� 3���� �� �����Ҷ� �ִ� �ݾ��� ���Ϸ��� �ϸ�,
				��� b '����' 1���� ���� �ִ� �ݾ�+c��� 2���� ����
						vs
				��� b '����' 2���� ���� �ִ�ݾ� + c��� 1���� ����
				�� ���ؾ� �Ѵ�. �̸� �Ϲݽ����� ��Ÿ���� �̷��� �ȴ�.*/ 
				
				if(dp[i][j] < dp[k][j-1] + table[i-k][j]){
					dp[i][j] = dp[k][j-1] + table[i-k][j];
				}
				
//				dp[i][j] = Max(dp[i][j], dp[k][j-1] + table[i-k][j]);
			}
		}
	}
	
//	cout << endl;
//	
//	for(int i = 1; i <= N; i++){
//		for(int j = 1; j <= M; j++){
//			cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}
//	
//	cout << endl;
//	for(int i = 1; i <= N; i++){
//		for(int j = 1; j <= M; j++){
//			cout << ratio[i][j] << " ";
//		}
//		cout << endl;
//	}

	cout << dp[N][M];
	
	
	
	
	
	return 0;
}
