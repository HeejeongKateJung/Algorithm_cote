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
queue<pair<int, int> > q; 	//���� ������ ��ġ�ϴ� ĭ�� �����ϴ� queue

int curDir = 0;


int main(void)
{
	cin >> N;
	cin >> numApple;
	
	//��� ��ġ�� map �� ����. 
	for(int i = 0; i < numApple; i++){
		int x, y;
		
		cin >> x >> y;
		
		map[x-1][y-1] = 1;
	}
	
	int numDirChange;
	cin >> numDirChange;
	
	//���� ��ȯ ������ queue�� �����Ѵ�. 
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
		
		
		//Ż�� ����
		//���� �ڰų� ������ �ε����� Ż��
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
		
//		//������ ����Ʈ
//		cout << endl;
//		for(int i = 0; i <= N; i++){
//			for(int j = 0; j <=N; j++){
//				cout << snake[i][j] << " ";
//			}
//			cout << endl;
//		} 
//		cout << endl;
		
		
		pair<int, char> dcInfo = infoDirChange.front();
		
		//������ �ٲ�� �ϴ� �������� üũ�Ѵ�. 
		if(dcInfo.first == count){
//			cout << "���� �ٲ����: "<< dcInfo.first; 
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
