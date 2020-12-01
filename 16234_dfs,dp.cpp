#include <iostream>
#include <cmath>
using namespace std;


int result;
int N, L, R;
int A[51][51];
int visit[51][51];

int dX[4] = {1, -1, 0, 0};
int dY[4] = {0, 0, 1, -1};

int unionNum, unionSum;

void dfs(int r, int c)
{
	 
	//��� ���⿡ ���Ͽ� 
	for(int i = 0; i < 4; i++){
		
		int nx = c+dX[i];
		int ny = r+dY[i];
		
		//������ ����� �κ��� ���� 
		//Ȥ�� �̹� �湮�� ���̸� 
		if(nx >= N || ny >= N || nx < 0 || ny < 0 || visit[ny][nx] == 1){
			continue;
		}
		
//		cout << A[ny][nx] << endl;
		
		int gap = abs(A[r][c]-A[ny][nx]);
		
		if(gap > R || gap < L){
			cout << "�������ƴ� " << endl; 
			continue;
		}
		
		if(visit[ny][nx] == 0){
			unionSum+=A[ny][nx];
			unionNum++;
			visit[ny][nx] = 1;
			dfs(ny, nx);
		}
	}
	
//	cout << "unionNum: " << unionNum << endl;
//	cout << "unionSum: " << unionSum << endl;
}


int main(void)
{
	cin >> N >> L >> R;
	
		
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> A[i][j];
		}
	}
	
	//�� �������� ������ ���� �ٲ۵� �ٽ� �����Ѵ�.
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << result << "��° ����" << endl; 
		
			dfs(i,j);
			
			if(unionNum == 0){
				continue;
			}
			
			int population = unionSum/unionNum;
			result++;
			
			for(int i = 0; i < N; i++){
				for(int j = 0; j < N; j++){
					if(visit[i][j]){
						A[i][j] = population;
					}
				}
			}
			
			unionNum = unionSum = 0;
			
			for(int i = 0; i < N; i++){
				for(int j = 0; j < N; j++){
					cout << A[i][j] << " ";
				}
				cout << endl;
			}
		}
	}
	
	cout << "result: " << result << endl;
	
	
	
	return 0;	
}
