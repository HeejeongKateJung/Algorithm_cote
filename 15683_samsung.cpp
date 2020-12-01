#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[9][9];

int ans= 100000;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1}; 


struct CCTV{
	int r, c, type; 
};

CCTV cctv[9];
int cctv_cnt= 0;

void print(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

void copyMap(int (*A)[9], int (*B)[9]){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			A[i][j] = B[i][j];
		}
	}
}

void seeThrough(int dir, int y, int x){
	
	switch(dir){
		
		//���� 
		case 0:
			for(int i = y-1; i >= 0; i--){
				if(map[i][x] == 6){
					break;
				}
				map[i][x] = -1;
			}
			break;
		
		//����
		case 1:
			for(int i = x+1; i < M; i++){
				if(map[y][i] == 6){
					break;
				}
				map[y][i] = -1;
			}
			break;
		
		//���� 
		case 2:
			for(int i = y+1; i < N; i++){
				if(map[i][x] == 6){
					break;
				}
				
				map[i][x] = -1;
			}
			break;
		
		//����
		case 3:
			for(int i = x-1; i >= 0; i--){
				if(map[y][i] == 6){
					break;
				}
				
				map[y][i] = -1;
			}
			break;
		 
	}
}


void update(int cnt){
	
//	print();
//	cout << "cnt: " << cnt << endl;
	if(cnt == cctv_cnt){
		int notObserved = 0;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				if(map[i][j] == 0){
					notObserved++;
				}
			}
		}
		
		if(ans > notObserved){
			ans = notObserved;
		}
		
		return;
	}
	
	int type = cctv[cnt].type;
	int y = cctv[cnt].r;
	int x = cctv[cnt].c;
	
//	cout << type << " " << y << " " << x << endl;
	
	int temp[9][9];
	copyMap(temp, map);
	
	switch(type){
		case 1:
			for(int i = 0; i < 4; i++){
				seeThrough(i, y, x);
				update(cnt+1);
				
				//dfs �̱� ������ ��� cctv�� �� ���� ������ �� ó������ ���ƿ��µ�,
				//�� �� ó�� ������ map�� �ʿ��ϱ� ������ temp�� �����ص� map��
				//������ �ٽ� for���������� ���̴�. 
				copyMap(map, temp);
			}
			break;
		
		case 2:
			for(int i = 0; i < 2; i++){
				seeThrough(i, y, x);
				seeThrough(i+2, y, x);
				update(cnt+1);
				
				copyMap(map, temp);
			}
			break;
		
		case 3:
			
			for(int i = 0; i < 4; i++){
				seeThrough(i, y, x);
				seeThrough((i+1)%4, y, x);
				update(cnt+1);
				
				copyMap(map, temp);
			}
			break;
			
		case 4:
			for(int i = 0; i < 4; i++){
				seeThrough(i, y, x);
				seeThrough((i+1)%4, y, x);
				seeThrough((i+2)%4, y, x);
				update(cnt+1);
				
				copyMap(map, temp);
			}
			break;
			
		case 5:
			for(int i = 0; i < 4; i++){
				seeThrough(i, y, x);
			}
			
			update(++cnt);
	}
	
}


int main(void)
{
	
	cin >> N >> M;
	
	cctv_cnt = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
						
			cin >> map[i][j];
			
			if(map[i][j] != 0 && map[i][j] != 6){
				cctv[cctv_cnt].r = i;
				cctv[cctv_cnt].c = j;
				cctv[cctv_cnt].type = map[i][j];
//				cout << "D" << endl;
				cctv_cnt++;
			}
			
		}
	}
	
//	cout << "CCTV count: " << cctv_cnt << endl;
	
	update(0);
	cout << ans << endl;
	
	
	return 0;
}
