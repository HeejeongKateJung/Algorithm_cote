#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int M, N;
int ans, turn, cnt;
//turn: 한번의 turn까지 몇개의 position쌍이  포함되는지 알려줌.
//cnt: 
//ans: 전체 턴 수 
vector<vector<int> > Map;
queue<pair<int,int> > q;
vector<vector<bool> > visited(1000, vector<bool>(1000));

void print(){
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			cout << Map[i][j] << " ";
		}
		
		cout << endl;
	}
}


int main(void)
{
	cin >> N >> M;
	
	
	for(int i = 0; i < M; i++){
		vector<int> v;
		for(int j = 0; j < N; j++){
			int a;
			cin >> a;
			v.push_back(a);
			
			if(a == 1){
				q.push(make_pair(i, j));
				turn++;
			}
		}
		Map.push_back(v);
	}
	
	while(!q.empty()){
		cnt = 0;
		for(int i = 0; i < turn; i++){
			
			int x = q.front().first;
			int y = q.front().second;
			
			q.pop();
			visited[x][y] = true;
			
			for(int i = 0; i < 4; i++){
				int nx = x+dx[i];
				int ny = y+dy[i];
				
				if(nx < 0 || ny < 0 || nx >= M || ny >= N || Map[nx][ny] != 0
				|| visited[nx][ny]){
					continue;
				}
				
				Map[nx][ny] = 1;
				q.push(make_pair(nx, ny));
				cnt++;	
				
			}
		}
		
		turn = cnt;
		ans++;
//		print();
	}
	
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			if(Map[i][j] == 0){
				cout << -1 << endl;
				return 0;
			}
		}
	}
	
	cout << ans-1 << endl;
	
	return 0;
} 
