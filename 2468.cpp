#include <iostream>

using namespace std;

int N, Map[101][101];

int R;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
bool visit[101][101];


void dfs(int y, int x) {
	
//	cout << "cur: " << Map[y][x] << " at "<< y << " " << x << endl;
	
	for(int k = 0; k < 4; k++){
		int ny = y+dy[k];
		int nx = x+dx[k];
		
		if(ny < 0 || nx < 0 || ny >= N || nx >= N)	continue;
		
		if(visit[ny][nx] || Map[y][x] <= R)	continue;
		
		visit[ny][nx] = true;
		dfs(ny, nx);
	}
	
}

int main(void)
{
	cin >> N;
	int max_rain = 0;
	int min_rain = 101;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> Map[i][j];
			if(Map[i][j] > max_rain)	max_rain = Map[i][j];
			if(Map[i][j] < min_rain)	min_rain = Map[i][j];
		}
	}
	
	int ans = 1;
	R = min_rain;
	while(R < max_rain){
//		cout << "R: " << R << endl;
		
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				visit[i][j] = false;
			}
		}
		
		int cnt = 0;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(Map[i][j] > R && !visit[i][j]){
//					cout << "안전지대 시작: " << i << " " << j << endl; 
					visit[i][j] = true;
					cnt++;
					dfs(i,j);
				}
			}
		}
		
//		cout << cnt << endl;
		if(ans < cnt)	ans = cnt;
		
		R++;
	}
	
	
	cout << ans << endl;
	return 0;
}
