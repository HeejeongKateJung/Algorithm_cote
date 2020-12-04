#include <iostream>

using namespace std;


int m, n, map[501][501];
int dp[501][501], visit[501][501];

//동서남북순 
int dM[4] = {0, 0, 1, -1};
int dN[4] = {1, -1, 0, 0}; 

int Max(int x, int y){
	return x > y ? x : y;
}

int search(int i, int j){\
	//만약 종점일 경우 1 반환 
	if(i == m-1 && j == n-1){
		return 1;
	}
	
	//이미 방문했을 경우 dp 값을 반환 
	if (visit[i][j]){
		return dp[i][j];
	}
	
	//방문한적 없는 노드일 경우 사방을 살핀다. 
	for(int k = 0; k < 4; k++){
		int ni = i+dM[k];
		int nj = j+dN[k];
		
		//map 범위를 넘어갈 경우 연산하지 않는다.		
		if(ni >= m || ni < 0 || nj >= n || nj < 0){
			continue;
		}
		
		//현재 노드가 주변 노드보다 큰 경우 
		//주변 노드로 뻗어 나갈 수 있다는 뜻이므로
		//주변 노드를 깊이 우선 탐색 한다. 
		if(map[i][j] > map[ni][nj]){
			
			dp[i][j] += search(ni, nj);
			
			//탐색이 끝나고 dp 값이 할당된 후에 방문했다고 표시한다. 
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
