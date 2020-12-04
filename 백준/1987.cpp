#include <iostream>
#include <map>

using namespace std;
int N, M;
char Map[21][21];

map<char, int> m;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int ans = 0;
bool visit[21][21];
void dfs(int y, int x){
		
	char cur = Map[y][x];
//	cout << "cur: " << cur << " of "<< y << " " << x <<  endl;
	//만약 map 에 이번 애가 존재하면 리턴 
	ans = ans > m.size() ? ans : m.size();
//	cout << "cnt: " << ans << endl;
	
	for(int i = 0; i < 4; i++){
		int ny = y+dy[i];
		int nx = x+dx[i];
		char next = Map[ny][nx];	
		if(ny < 0 || nx < 0 || ny >= N || nx >= M)
			continue;
		
		if(m.find(next) != m.end()){
//			cout << next << " 는 이미 지나옴" << endl;	
			continue;
		}
		
		m.insert(make_pair(next, 1));		
		dfs(ny, nx);
		m.erase(next);
	}
}

int main(void)
{
	cin >> N >> M;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> Map[i][j];
		}
	}
	m.insert(make_pair(Map[0][0], 1));
	dfs(0,0);
	
	cout << ans << endl;
	return 0;
}
