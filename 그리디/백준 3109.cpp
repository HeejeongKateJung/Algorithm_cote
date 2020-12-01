#include <iostream>
#include <vector>
#define MAX 10000
using namespace std;

int R, C;
bool visit[MAX][500];
bool ans = 0;
int answer = 0;
vector<vector<int> > map;
int dx[] = {-1, 0, 1};
int dy[] = {1, 1, 1};

void dfs(int x, int y)
{
	
	visit[x][y] = true;
	
	if(y == C-1){
		ans = true;
		answer++;
		return;
	}
	
	for(int i = 0; i < 3; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(nx >= R || ny >= C || nx < 0 || ny < 0){
			continue;
		}
		if(map[nx][ny] == 'x' || visit[nx][ny] == true){
			continue;
		}
		
		dfs(nx, ny);
		if(ans == true){
			return;
		}
	}
	
}

int main(void)
{
	cin >> R >> C;
	
	for(int i = 0; i < R; i++){
		vector<int> v;
		for(int j = 0; j < C; j++){
			char c;
			cin >> c;
			v.push_back(c);		
		}
		map.push_back(v);
	}
	
	for(int i = 0; i < R; i++){
		ans = false;
		dfs(i, 0);
	}
	
	cout << answer << endl;
	return 0;
}
