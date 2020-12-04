#include <iostream>
#include <queue>
using namespace std;

int map[101][101];
int snake[101][101];
int count;
int N, numApple;

int posY[4] = {0, 1, 0, -1};
int posX[4] = {1, 0, -1, 0};

queue<pair<int, char> > infoDirChange;
queue<pair<int, int> > q; 	//뱀의 몸통이 위치하는 칸을 저장하는 queue

int curDir = 0;


int main(void)
{
	cin >> N;
	cin >> numApple;
	
	//사과 위치를 map 에 저장. 
	for(int i = 0; i < numApple; i++){
		int x, y;
		
		cin >> x >> y;
		
		map[x-1][y-1] = 1;
	}
	
	int numDirChange;
	cin >> numDirChange;
	
	//방향 전환 정보를 queue에 저장한다. 
	for(int i = 0; i < numDirChange; i++){
		int time;
		char dir;
		cin >> time >> dir;
		infoDirChange.push(make_pair(time, dir));
	}
	
	int x = 0;
	int y = 0; 
	
	q.push(make_pair(y, x));
	
	while(!q.empty()){
		
		count++;
		
		pair<int, int> head = q.back();
		
		y = head.first + posY[curDir];
		x = head.second + posX[curDir];
		
		
		//탈출 조건
		//벽을 박거나 꼬리에 부딪히면 탈출
		if(snake[y][x] == 1 || x < 0 || x >= N || y < 0 || y >= N){
			break;
		}
		
		q.push(make_pair(y, x));
		
		if(map[y][x] == 1){
			snake[y][x] = 1;
			map[y][x] = 0;
		}
		else{
			snake[y][x] = 1;
			
			pair<int, int> tail = q.front();
			
			snake[tail.first][tail.second] = 0;
			q.pop();
		}
		
//		//디버깅용 프린트
//		cout << endl;
//		for(int i = 0; i <= N; i++){
//			for(int j = 0; j <=N; j++){
//				cout << snake[i][j] << " ";
//			}
//			cout << endl;
//		} 
//		cout << endl;
		
		
		pair<int, char> dcInfo = infoDirChange.front();
		
		//방향을 바꿔야 하는 차례인지 체크한다. 
		if(dcInfo.first == count){
//			cout << "방향 바꿔야함: "<< dcInfo.first; 
			if(dcInfo.second == 'D'){
				curDir = (curDir+1)%4;
			}else{
				curDir = (curDir-1+4)%4;
			}
			
			infoDirChange.pop();
		}
	}
	
	cout << count << endl;
	
	
	return 0;
}
