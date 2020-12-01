#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, start;
bool visited[1001];
bool visitedd[1001];
queue<int> q;

int map[1001][1001];

void bfs(int start){
	visited[start] = 1;
	q.push(start);
	//모든 노드에 대해서 
	while(!q.empty()){
		int curNode = q.front();
		q.pop();
		
		cout << curNode << " ";
		
		
		//각 간선마다 확인 
		for(int j = 1; j <= N; j++){
			
			if(!visited[j] && map[curNode][j]){
				visited[j] = true;
				q.push(j);
			}
				
			
		}
		
		
	}
} 

void dfs(int node){
	
	cout << node << " ";
	visitedd[node] = true;
	
	for(int i = 1; i <= N; i++){
		if(!visitedd[i] && map[node][i]){
			dfs(i);
		}
		
	}
	
}

int main(void)
{
	cin >> N >> M >> start;
	for(int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	
	
	dfs(start);
	
	cout << endl;
	
	bfs(start);
	cout << endl;
	
	
	return 0;
}
