#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N;
char Map[51][51];
queue<pair<int, int> > q;
vector<int> answer;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

bool visited[51][51];

void print(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << Map[i][j] << " ";
		}
		cout << endl;
	}
}

void bfs(int sy, int sx){
	int cnt = 1;
	q.push(make_pair(sy, sx));
	visited[sy][sx] = true;
	
	while(!q.empty()){
		
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for(int k = 0; k < 4; k++){
			int ny = y+dy[k];
			int nx = x+dx[k];
			
			if(ny >= N || nx >= N || ny < 0 || nx < 0)	continue;
			if(visited[ny][nx])	continue;
			if(Map[ny][nx] != '1')	continue;
			
			visited[ny][nx] = true;
			++cnt;
			q.push(make_pair(ny, nx));
		}
	}
	
//	cout << cnt << endl;
	answer.push_back(cnt);
	
}

int main(void)
{
	cin >> N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> Map[i][j];
		}
	}
//	print();
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			
			if(Map[i][j] == '1' && !visited[i][j]){
				bfs(i, j);
			}
			
			
		}
	}
	
	sort(answer.begin(), answer.end());
	
	cout << answer.size() << endl;
	for(int i = 0; i < answer.size(); i++){
		cout << answer[i] << endl;
	}
	return 0;
} 

