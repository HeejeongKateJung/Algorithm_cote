#include <iostream>
#include <queue>
using namespace std;


int Map[101][101];
int n, m;
int visit[101][101];
int count[101][101];


int bfs(int i, int j){
	queue<pair<int, int> > q;
	
	q.push(make_pair(i, j));
	
	while(!q.empty()){
		
		int x = q.front().second;
		int y = q.front().first;
		
		
		visit[x][y] = 1;
		
		q.pop();
		
		//���� ����Ǿ��ְ�, �湮�� �� ���� ��带 �湮�ؾ� �Ѵ�.
		for(int k = 0; k < 4; k++){
			
		} 
		
	}
	
}

int main(void)
{
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> Map[n][m];
		}
	}
	
	
	
	
	
	return 0;
}
