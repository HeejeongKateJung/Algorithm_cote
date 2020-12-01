#include <iostream>
#include <vector>
using namespace std;

int map[21][21];
int direction, N, M, x, y, K; 

//¡÷ªÁ¿ß 1¿Ã ¿≠∏È, 6¿Ã æ∆∑ß∏È 
int dice[7], temp[7];

//µø:1 º≠: 2 ∫œ: 3 ≥≤: 4 
int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};

//¡§¥‰ πËø≠
vector<int> top;
vector<int>::iterator it;

void changeDice(int d){
	
	for(int i = 0; i <= 7; i++){
		temp[i] = dice[i];
	}
	//µø:1 º≠: 2 ∫œ: 3 ≥≤: 4 
	if(d == 1){
		dice[1] = temp[4];
		dice[6] = temp[3];
		dice[3] = temp[1];
		dice[4] = temp[6];
	}
	else if(d == 2){
		dice[1] = temp[3];
		dice[6] = temp[4];
		dice[4] = temp[1];
		dice[3] = temp[6];
	}
	else if(d == 3){
		dice[1] = temp[5];
		dice[6] = temp[2];
		dice[2] = temp[1];
		dice[5] = temp[6];
	}
	else if(d == 4){
		dice[1] = temp[2];
		dice[6] = temp[5];
		dice[2] = temp[6];
		dice[5] = temp[1];
	}
}

int main(void)
{
	
	cin >> N >> M >> y >> x >> K;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> map[i][j];
		}
	}
	
	for(int i = 0; i < K; i++){
		cin >> direction;
		
		int nx = dx[direction]+x;
		int ny = dy[direction]+y;
		
		if(nx >= M || ny >= N || nx < 0 || ny < 0){
			continue;
		}
		
		
		changeDice(direction);
		//¿≠∏È∞˙ æ∆∑ß∏È¿« ∞™¿ª πŸ≤€¥Ÿ.
		if(map[ny][nx] == 0){
			map[ny][nx] = dice[6];
		}else{
			dice[6] = map[ny][nx];
			map[ny][nx] = 0;
		}
		
		x = nx;
		y = ny;
		
		top.push_back(dice[1]);
		
	}
	
	for(it = top.begin(); it != top.end(); it++){
		cout << *it << endl;
	}
	
	
	
	return 0;
}



