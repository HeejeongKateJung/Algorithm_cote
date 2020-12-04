#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int map[51][51];
int temp[51][51];
int r, c, time;

//��.��.��.��. ���� 
int dirY[4] = {0, 1, 0, -1};
int dirX[4] = {1, 0, -1, 0}; 

pair<int,int> airCleaner[2];

void spread(){
	int leftDust[51][51];
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			leftDust[i][j] = map[i][j];
			temp[i][j] = 0;
		}
	}
	
	
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if(map[i][j] > 0){
				
				for(int k = 0; k < 4; k++){
					int nY = i+dirY[k];
					int nX = j+dirX[k];
					
					if(nX < 0 || nY < 0 || nX >= c || nY >= r || map[nY][nX] == -1){
						continue;
					}
					
					temp[nY][nX] += map[i][j]/5;
					leftDust[i][j] = leftDust[i][j] - map[i][j]/5;
					
				}
				
				
			}
		}
	}
	
	

	
	
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			map[i][j] = temp[i][j];
			map[i][j] += leftDust[i][j];
		}
	}
	
//	cout << endl;
//	for(int i = 0; i < r; i++){
//		for(int j = 0; j < c; j++){
//			cout << map[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
	
}

void circulateUpper(){
	
	//����û���� ���� ��ȯ
	
	//1. ����û���� ���ʺ��� (0,0)���� ���� ������ �����.
	for(int i = airCleaner[0].first-1; i > 0; i--){
		map[i][0] = map[i-1][0];
	}
	
	//2. �� ������ ���� �����ʱ��� ���� �������� �����.
	for(int i = 0; i < c-1; i++){
		map[0][i] = map[0][i+1];
	}
	
	//3. ������ �غ��� ������ ������ ���� ���� �����.
	for(int i = 1; i <= airCleaner[0].first; i++){
		map[i-1][c-1] = map[i][c-1];
	}
	
	//4. ����û���Ⱑ �ִ� ������ ������ ��� ���������� �����.
	for(int i = c-1; i > 1; i--){
		map[airCleaner[0].first][i] = map[airCleaner[0].first][i-1];
	}
	
	map[airCleaner[0].first][1] = 0;
	
}

void circulateLower(){
	int loc = airCleaner[1].first;
	
	//1. ��û�� ��ġ ���ζ��� ���� ����� 
	for(int i = loc+1; i < r; i++){
		map[i][0] = map[i+1][0];
	}
	
	//2. �� �Ʒ� ���ζ��� �������� ����� 
	for(int i = 0; i < c-1; i++){
		map[r-1][i] = map[r-1][i+1];
	}
	
	//3. �� ������ ���ζ��� ������ ������ 
	for(int i = r-1; i >= loc; i--){
		map[i+1][c-1] = map[i][c-1];
	}
	
	//4. ��û�� ���ζ��� ���������� ����� 
	for(int i = c-1; i > 1; i--){
		map[loc][i] = map[loc][i-1]; 
	}
	
	map[loc][1] = 0;

//	cout << endl;
//	for(int i = 0; i < r; i++){
//		for(int j = 0; j < c; j++){
//			cout << map[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;

}


int main(void)
{
	cin >> r >> c >> time;
	
	int idx = 0;
	
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cin >> map[i][j];
			
			//����û���� i ��ġ�� �����Ѵ�. 
			if(map[i][j] == -1){
				airCleaner[idx].first = i;
				airCleaner[idx].second = j;
				idx++;	
			}
		}
	}
	
	for(int i = 0; i < time; i++){
		spread();	//�̼����� Ȯ��
		circulateUpper();
		circulateLower();

	}
	
	int result = 0;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
				
			if(map[i][j] != -1){
				result+=map[i][j];
			}
		}
	}
	
	cout << result;
	return 0;
}
