#include <iostream>
#include <vector>
using namespace std;

int n, count;
int map[101][101];
int visit[101];

void dfs(int node){
	
	//일단 이 노드는 방문함. 
	visit[node] = 1;
	
	for(int i = 1; i <= n; i++){
		//나랑 연결되어 있고, 방문도 안한 애들을 찾아서 
		if(visit[i] == 0 && map[node][i] == 1){
			//걔네를 방문했다고 표시하고 
			count++;
			
			//걔네에게 연결된 애들을 또 찾는다. 
			dfs(i);
		}
	}
}

int main(void)
{	
	cin >> n;
	int link;
	cin >> link;
	
	for(int i = 0; i < link; i++){
		int first, second;
		cin >> first >> second;
		map[first][second] = map[second][first] = 1;
	}
	
	dfs(1);
	 
	cout << count << endl;
	
	return 0;
}
