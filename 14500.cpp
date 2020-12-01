#include <iostream>
#include <cstring>
using namespace std;

int N, M, Map[501][501];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int ans = 0;
bool visit[501][501];

void print(){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				cout << visit[i][j] << " ";
			}
			cout << endl;
		}
}

void dfs(int y, int x, int cnt, int sum){
	
	if(cnt == 4){
		
		if(ans < sum)	ans = sum;

		return;
	}
	
	for(int k = 0; k < 4; k++){
		int ny = y+dy[k];
		int nx = x+dx[k];
		
		if(ny < 0 || nx < 0 || ny >= N || nx >= M || visit[ny][nx])	continue;
		
		visit[ny][nx] = true;
		dfs(ny, nx, cnt+1, sum+Map[ny][nx]);
		visit[ny][nx] = false;
	}
}

void eo(int y, int x){
	int sum = 0;
	sum = Map[y][x] + Map[y+1][x]+Map[y+2][x]+Map[y+1][x-1];
	if(ans < sum) ans = sum;
}

void a(int y, int x){
	int sum = 0;
	sum = Map[y][x] + Map[y+1][x] + Map[y+2][x] + Map[y+1][x+1];
	if(ans < sum) ans = sum;
}

void o(int y, int x){
	int sum = 0;
	sum = Map[y][x] + Map[y][x+1] + Map[y][x+2] + Map[y-1][x+1];
	if(ans < sum) ans = sum;
}

void u(int y, int x){
	int sum = 0;
	sum = Map[y][x] + Map[y][x+1] + Map[y][x+2] + Map[y+1][x+1];
	if(ans < sum) ans = sum;
}

int main(void)
{
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> Map[i][j];
		}
	}	
	
	for (int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			memset(visit, false, sizeof(visit));
			visit[i][j] = true;
			dfs(i,j,1,Map[i][j]);
			if(i+2 < N && j-1 >= 0)	eo(i,j);
			if(i+2 < N && j+1 < M)	a(i,j);
			if(j+2 < M && i-1 >= 0)	o(i, j);
			if(j+2 < M && i+1 < N)	u(i,j);	
			
		}
	}
	
	cout << ans << endl;
	return 0;
}
