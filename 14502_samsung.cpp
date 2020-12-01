#include <iostream>
#include <queue>
using namespace std;

int N, M;
int Map[9][9], temp[9][9], spreadMap[9][9], visited[9][9];
queue<pair<int, int> > virus;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int result = 0;


void print(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cout << spreadMap[i][j] << " ";
		}
		cout << endl;
	}
}

void mapCopy(int (*A)[9], int (*B)[9]){
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			A[i][j] = B[i][j];
		}
	}
}


void spread(){
	
	mapCopy(spreadMap, temp);
	
	while(!virus.empty()){
		int y = virus.front().first;
		int x = virus.front().second;
		virus.pop();
		
		for(int i = 0; i < 4; i++){
			int ny = y+dy[i];
			int nx = x+dx[i];
			
			if(ny >= N || nx >= M || ny < 0 || nx < 0){
				continue;
			}
			
			if(spreadMap[ny][nx] == 0){
				spreadMap[ny][nx] = 2;
				virus.push(make_pair(ny, nx));
			}
			
		}
		
		
		
	}

	
}

void countSafeZone(){
	
	int numSafe = 0;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(spreadMap[i][j] == 0){
				numSafe++;
			}
		}
	}
	
	if(result < numSafe){
		result = numSafe;
	}
	
	return;
	
}



void makeWall(int count){
	
	//벽을 3개 세웠다면 바이러스를 퍼뜨린다. 
	if(count == 3){
		spread();
		print();
		countSafeZone();
//		cout << "count 3!!" << endl;
//		print();
		mapCopy(temp, Map);
		return;
	}
	

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			
			if(temp[i][j] == 0){
			
				temp[i][j] = 1;
				count++;
				makeWall(count);
				temp[i][j] = 0;
				count--;
			}else{
				return;
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
				virus.push(make_pair(i, j));
				
			}
		}
	}
	
	mapCopy(temp, Map);
	
	makeWall(0);
	
	cout << result << endl;
	
	return 0;
}
