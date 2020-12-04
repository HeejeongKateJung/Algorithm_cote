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
	//�ϴ� �湮�ߴٰ� ǥ���Ѵ�. 
	visit[node] = 1;
	v.push_back(node);
		
	for(int i = 1; i <= numNode; i++){
		
		//���� ����Ǿ��ְ�, �湮���� ���� ��带 �湮�Ѵ�.
		if(map[node][i] == 1 && visit[i] == 0){
			dfs(i);
		} 
	}
	
	
}

void bfs(int node){
	
	queue<int> q;
	
	q.push(node);
	//q�� ������������� �����ϴµ�,
	while(!q.empty()){
		
		node = q.front();
		visit[node] = 1;
		v.push_back(node);
		
		q.pop();
		
		for(int i = 1; i <= numNode; i++){
			//���� ����Ǿ��ְ�, �湮���� ���� ��带 q�� �ִ´�.
			if(map[node][i] == 1 && visit[i] == 0){
				
				visit[i] = 1; 
				//�׸��� ť���ٰ� ������ ������ node �� �־�д�.
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
