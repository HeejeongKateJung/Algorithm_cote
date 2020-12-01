#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 10000
using namespace std;

int N, M;
char map[101][101];
int visited[101][101];
int cnt[101][101];
queue<pair<int,int> > q;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void print(){
	for(int i = 1; i <= N; i++ ){
		for(int j = 1; j <= M; j++){
			cout << cnt[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << endl;
}

void bfs(int sy, int sx){
	
	visited[sy][sx] = 1;
	cnt[sy][sx] = 1;
	q.push(make_pair(sy,sx));
	
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for(int dir = 0; dir < 4; dir++){
			int ny = y+dy[dir];
			int nx = x+dx[dir];
			
			if(ny > N || nx > M || ny <= 0 || nx <= 0){
				continue;
			}
			
			if(map[ny][nx] != '1' || visited[ny][nx]){
				continue;
			}
//			cout << ny << " " << nx << " " << endl;
			q.push(make_pair(ny, nx));
			visited[ny][nx] = 1;
			cnt[ny][nx] = cnt[y][x]+1;
		}
		
		
//		print();
		
	}
	
	
}

int main(void)
{
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			char a;
			cin >> a;
			map[i][j] = a;
		}
	}

	bfs(1,1);
	
	cout << cnt[N][M] << endl;
	return 0;
}
