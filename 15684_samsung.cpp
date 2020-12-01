//시간 초과가 난 이유:
/**
	매번 dfs 를 돌릴 때마다 전체 배열을 복사하는 과정을 반복했기 때문.
	전체 배열을 복사하는 대신에 return 될 때마다
	그 이전에 바뀌었던 부분만 다시 원상태로 복구하는 식으로 해결하였다. 
*/ 


#include <iostream>
#include <vector>
using namespace std;


//각각 세로줄개수, 가로줄개수, 가로줄 자리 개수 
int N, M, H, map[32][32];
int ans = 100;


//vector<pair<int, int> > v;

void print(){
	for(int i = 1; i <= H; i++){
		for(int j = 1; j <= N; j++){
			cout << map[i][j] << " ";
		}
		
		cout << endl;
	}
//	cout << endl;
}

void copyMap(int (*A)[32], int (*B)[32]){
	for(int i = 1; i <= H; i++){
		for(int j = 1; j <= N; j++){
			A[i][j] = B[i][j];
		}
	}
}

bool check(){
	
	
	//사다리타기
	//bar: 시작지점의 bar
	//j: 사다리 다 타고 나서의 bar 
	for(int bar = 1; bar <= N; bar++){
		
		int j = bar;
		
		for(int i = 1; i <= H; i++){
//			cout << "map[i][j]: " << map[i][j] << endl;
			if(map[i][j] == 1){
				j++;
			}
			else if(map[i][j] == 2){
				j--;
			}	
		}
		
		

//		cout << "현재 bar: " << bar << endl; 
//		cout << "현재 j: " << j << endl; 
		if(j != bar){
			return false;
		}
	}
	
	return true;

}

void update(int idx, int cnt){
	
	if(cnt > 3){
		return;
	}
	
	
	//탈출조건: 사다리 check가 모두 맞고 추가한 가로바의 개수가 3 이하일때
	if(check()){
		
//		cout << "check is true" << endl << endl;
		if(ans > cnt){
			ans = cnt;
		}
		return;
	}
	
	int temp[32][32];
//	copyMap(temp, map);
	
	for(int i = idx; i <= H; i++){
		for(int j = 1; j < N; j++){
			
			//자신과 오른쪽이 모두 0일때만 가로bar 설치 가능
			if(map[i][j]!=0 || map[i][j+1]!=0){
				continue;
			}
			
			
			map[i][j] = 1;
			map[i][j+1] = 2;
			
			update(i, cnt+1);
			
			map[i][j] = 0;
			map[i][j+1] = 0;
			//copyMap(map, temp) 
			
		}
	} 
	
	
	
	
}

int main(void)
{
	
	cin >> N >> M >> H;
	for(int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		
		map[a][b] = 1;
		map[a][b+1] = 2;
	}
	
//	print();
	
	update(1, 0);
	
	if(ans > 3){
		cout << -1 << endl;
	}else{
		cout << ans << endl;
	}
	
	return 0;
}
