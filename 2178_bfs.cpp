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
		
		//나랑 연결되어있고, 방문한 적 없는 노드를 방문해야 한다.
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
