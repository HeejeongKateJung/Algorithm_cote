#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N, M;
char Map[51][51];
bool visit[51][51];
int count[51][51];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int ans, ansy, ansx, result;

void print(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cout << count[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void bfs(int y, int x){
	
	queue<pair<int,int> > q;
	
	q.push(make_pair(y,x));
	
	while(!q.empty()){
		int yy = q.front().first;
		int xx = q.front().second;
		
//		cout << "cur: " << yy << " " << xx << endl;
		q.pop();
		
		for(int k = 0; k < 4; k++){
			int ny = yy+dy[k];
			int nx = xx+dx[k];
		
			if(ny < 0 || nx < 0 || ny >= N || nx >= M || Map[ny][nx] == 'W' || visit[ny][nx])
				continue;
			
			count[ny][nx] = count[yy][xx]+1;
			visit[ny][nx] = true;
			
			if(ans < count[ny][nx]){
				ans = count[ny][nx];
			}
			
			q.push(make_pair(ny,nx));
		}
		
		
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
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(Map[i][j] == 'L'){
				memset(visit,false,sizeof(visit));
				memset(count,0,sizeof(count));
				visit[i][j] = true;
				bfs(i,j);
				
//				print();
				
				if(ans-count[i][j] > result)	result = ans-count[i][j];
				
			}
		}
	}
	
	cout << result << endl;
	

	return 0;
}
