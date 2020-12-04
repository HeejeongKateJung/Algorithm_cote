#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define MAX 51
using namespace std;
int N, M, empty_place;
int Map[MAX][MAX], temp[MAX][MAX];

vector<pair<int,int> > v;
bool visit[11];

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int ans = MAX*MAX;

void print(){
	cout << endl;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << temp[i][j] << " " ;
		}
		cout << endl;
	}
	cout << endl;
}

void spread(queue<pair<int,int> > q){
	int infected = 0;
	int time = 0;
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for(int k = 0; k < 4; k++){
			int ny = y+dy[k];
			int nx = x+dx[k];
			
			if(ny < 0 || nx < 0 || ny >= N || nx >= N)	continue;
			//temp[ny][nx] != -1 �� ���: �̹� Ž���� ĭ 
			if(Map[ny][nx] == 1 || temp[ny][nx] != -1) continue;
			
			temp[ny][nx] = temp[y][x]+1;
			
			//�� Ȱ��ȭ���� ���� ���̷����� �ǵ帮�� ��츦 �� ������ ��쿡�� 
			if(Map[ny][nx] == 0){
				infected++;
				time = temp[ny][nx];
//				cout << "time of "<< ny << " " << nx << " : " << time << endl;
			}
			q.push(make_pair(ny,nx));
		}
	}

//	print();
	
	//���� ������ �� ���µ��� ���ϴ� answer �� ���� �亸�� �۾Ƽ� ������ ���ΰ� 
	if(infected == empty_place)	ans = ans < time ? ans : time;
}

void select(int idx, int cnt){
	
	if(cnt == M){
		
		queue<pair<int,int> > q;
		memset(temp, -1, sizeof(temp));
		
		for(int i = 0; i < v.size(); i++){
			if(visit[i]){
				q.push(make_pair(v[i].first, v[i].second));
				temp[v[i].first][v[i].second] = 0;
			}
		}
		
		spread(q);
		
		return;
	}
	
	for(int i = idx; i < v.size(); i++){
		
		if(visit[i])	continue;
		
		visit[i] = true;
		
		select(i+1, cnt+1);
		
		visit[i] = false;
		
	}
}


int main(void)
{
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> Map[i][j];
			if(Map[i][j] == 2){
				v.push_back(make_pair(i,j));
			}
			if(Map[i][j] == 0){
				empty_place++;
			}
		}
	}
	
	select(0,0);
	
	
	if(ans == MAX*MAX)	cout << -1 << endl;
	else cout << ans << endl; 
	
	
	return 0;
}
