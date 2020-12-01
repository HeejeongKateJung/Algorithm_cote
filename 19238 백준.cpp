#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, oil;
int Map[21][21];
vector<pair<int, int> start, int distance> v;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int get_min_dist(pair<int,int> start, pair<int,int> end){
	int visited[N+1][N+1];
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <=N; j++){
			visited[i][j] = -1;
		}
	}
	
	visited[start.first][start.second] = 0;
	
	queue<pair<int,int> > q;
	
	q.push(make_pair(start.first, start.second));
	int cnt = 0;
	
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		if(y == end.first && x == end.second){
			break;
		}
		
		
		for(int i = 0; i < 4; i++){
			
			int ny = y+dy[i];
			int nx = x+dx[i];
			
			if(ny > N || nx > N || ny <= 0 || nx <= 0 || visited[ny][nx] != -1
			|| Map[ny][nx] == 1){
				continue;
			}
			
			q.push(make_pair(ny, nx));
			visited[ny][nx] = visited[y][x]+1;	
		}
	}
	
	return visited[end.first][end.second];
	
	
}

int main(void)
{
	cin >> N >> M >> oil;
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cin >> Map[i][j];
		}
	}
	int s_y, s_x;
	cin >> s_y >> s_x;
	
	for(int i = 0; i < M; i++){
		int x, y, nx, ny;
		cin >> y >> x >> ny >> nx;
		int dist = get_min_dist(make_pair(y, x), make_pair(ny, nx));
		
		//vector 원소 형태: [[y,x], min_distance to destination] 
		v.push_back(make_pair(y, x), dist);
	}
	
	
	
	
	return 0;
}
