//�ð� �ʰ��� �� ����:
/**
	�Ź� dfs �� ���� ������ ��ü �迭�� �����ϴ� ������ �ݺ��߱� ����.
	��ü �迭�� �����ϴ� ��ſ� return �� ������
	�� ������ �ٲ���� �κи� �ٽ� �����·� �����ϴ� ������ �ذ��Ͽ���. 
*/ 


#include <iostream>
#include <vector>
using namespace std;


//���� �����ٰ���, �����ٰ���, ������ �ڸ� ���� 
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
	
	
	//��ٸ�Ÿ��
	//bar: ���������� bar
	//j: ��ٸ� �� Ÿ�� ������ bar 
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
		
		

//		cout << "���� bar: " << bar << endl; 
//		cout << "���� j: " << j << endl; 
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
	
	
	//Ż������: ��ٸ� check�� ��� �°� �߰��� ���ι��� ������ 3 �����϶�
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
			
			//�ڽŰ� �������� ��� 0�϶��� ����bar ��ġ ����
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
