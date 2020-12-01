#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int numNode, numLink, start;
int map[1001][1001];
int visit[1001];
vector<int> v;
vector<int>::iterator iter;

void dfs(int node){
	//일단 방문했다고 표시한다. 
	visit[node] = 1;
	v.push_back(node);
		
	for(int i = 1; i <= numNode; i++){
		
		//나랑 연결되어있고, 방문한적 없는 노드를 방문한다.
		if(map[node][i] == 1 && visit[i] == 0){
			dfs(i);
		} 
	}
	
	
}

void bfs(int node){
	
	queue<int> q;
	
	q.push(node);
	//q가 비어있을때까지 실행하는데,
	while(!q.empty()){
		
		node = q.front();
		visit[node] = 1;
		v.push_back(node);
		
		q.pop();
		
		for(int i = 1; i <= numNode; i++){
			//나랑 연결되어있고, 방문한적 없는 노드를 q에 넣는다.
			if(map[node][i] == 1 && visit[i] == 0){
				
				visit[i] = 1; 
				//그리고 큐에다가 다음에 실행할 node 를 넣어둔다.
				q.push(i); 
			} 
		}
		
		
		
	} 
}


int main(void)
{
	cin >> numNode >> numLink >> start;
	
	for(int i = 0; i < numLink; ++i){
		int first, second;
		cin >> first >> second;
		
		map[first][second] = map[second][first] = 1;
	}
	
//	dfs(start);
	bfs(start);
	
	for(iter = v.begin(); iter!=v.end(); iter++){
		cout << *iter << " ";
	}
	cout << endl;
	
	
	return 0;
}
