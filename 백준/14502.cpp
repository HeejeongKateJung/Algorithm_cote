#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 9
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int N, M, Map[MAX][MAX], temp[MAX][MAX] ,ans;

vector<pair<int,int> > virus;

void print(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cout << temp[i][j] << " ";
		}
		cout << endl;
	}
}

void spread(){
	
	
	queue<pair<int, int> > q;
	
	for(int i = 0; i < virus.size(); i++){
		q.push(make_pair(virus[i].first, virus[i].second));
	}
	
	while(!q.empty()){
		//바이러스가 있는 곳에서 퍼지기 시작함.
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for(int k = 0; k < 4; k++){
			int ny = y+dy[k];
			int nx = x+dx[k];
			
			if(ny >= N || nx >= M || ny < 0 || nx < 0 || temp[ny][nx] != 0) continue;
			
			temp[ny][nx] = 2;
			q.push(make_pair(ny, nx));
		}
		
	}
	
	int space = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(temp[i][j] == 0)	space++;
		}
	}
	
	if(ans < space)	ans = space;
	
	return;
	
}

void make_wall(int cnt){
	
	if(cnt == 3){
		
//		cout << "퍼뜨리기" << endl;
		memcpy(temp, Map, sizeof(Map));
		spread();	
		return;
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			
			if(Map[i][j] == 0){
				Map[i][j] = 1;
				make_wall(cnt+1);
				Map[i][j] = 0;
			}
			
		}
	}

}


int main(void)
{
	cin >> N >> M;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> Map[i][j];
			
			if(Map[i][j] == 2){
				virus.push_back(make_pair(i,j));
			}
		}
	}
	
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(Map[i][j] == 0){
				//0인곳마다 벽을 하나 세우고
				Map[i][j] = 1;
				make_wall(1);
				
				//리턴되면 취소한다. 
				Map[i][j] = 0; 
			}
		}
	}
	
	cout << ans << endl;

	return 0;
}
