#include <iostream>

using namespace std;


int m, n, map[501][501];
int dp[501][501], visit[501][501];

//�������ϼ� 
int dM[4] = {0, 0, 1, -1};
int dN[4] = {1, -1, 0, 0}; 

int Max(int x, int y){
	return x > y ? x : y;
}

int search(int i, int j){\
	//���� ������ ��� 1 ��ȯ 
	if(i == m-1 && j == n-1){
		return 1;
	}
	
	//�̹� �湮���� ��� dp ���� ��ȯ 
	if (visit[i][j]){
		return dp[i][j];
	}
	
	//�湮���� ���� ����� ��� ����� ���ɴ�. 
	for(int k = 0; k < 4; k++){
		int ni = i+dM[k];
		int nj = j+dN[k];
		
		//map ������ �Ѿ ��� �������� �ʴ´�.		
		if(ni >= m || ni < 0 || nj >= n || nj < 0){
			continue;
		}
		
		//���� ��尡 �ֺ� ��庸�� ū ��� 
		//�ֺ� ���� ���� ���� �� �ִٴ� ���̹Ƿ�
		//�ֺ� ��带 ���� �켱 Ž�� �Ѵ�. 
		if(map[i][j] > map[ni][nj]){
			
			dp[i][j] += search(ni, nj);
			
			//Ž���� ������ dp ���� �Ҵ�� �Ŀ� �湮�ߴٰ� ǥ���Ѵ�. 
			visit[i][j] = 1;
		}
				
	}
	
	return dp[i][j];
}

int main(void)
{
	cin >> m >> n;
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> map[i][j];
		}
	}
	
	dp[m-1][n-1] = 1;
	
	search(0,0);
	
	cout << dp[0][0];
	
//	for(int i = 0; i < m; i++){
//		
//		for(int j = 0; j < n; j++){
//			
//			cout << dp[i][j];
//			
//			
//		}
//		
//		cout << endl;
//	}
	
	
	return 0;
}
