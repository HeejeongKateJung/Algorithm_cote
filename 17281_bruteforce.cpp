#include <iostream>
#include <vector>
#include <cstring>
#define MAX 51
using namespace std;

int N, ans;
int arr[MAX][10];
bool visit[MAX];
int order[10];

void print(){
	for(int i = 1; i <= 9; i++){
		cout << order[i] << " ";
	}
	cout << endl;
}

void play() {
	int score = 0;
	int start = 1;
	int base_state[4];
	
	for(int i = 1; i <= N; i++){
		int out_cnt = 0;
		bool next_ining = false;
		memset(base_state, 0, sizeof(base_state));
		
		//아웃이 3번 나올때까지 반복 
		while(1){
			for(int j = start; j <= 9; j++){
				int player = arr[i][order[j]];
				
				if(player == 0) out_cnt++;
				else if(player >= 1 && player <= 4){
					
					//각 루에 있던 선수들이 이동한다.
					for(int ru = 3; ru >= 1; ru--){
						if(base_state[ru] == 1){
							base_state[ru]--;
							if(ru+player > 3) {
								score++;
							}else{
								base_state[ru+player]++;
							}
							
						}
					}
					
					base_state[player] = 1;
//					for(int ru = 3; ru >= 1; ru--){
//						cout << base_state[ru] << " ";
//					}
//					cout << endl;
				}
				else if(player == 4){
					for(int ru = 3; ru >= 1; ru--){
						
						base_state[ru] = 0;
						if(base_state[ru] == 1) score++;
					}
					score++;
				}
				
				if(out_cnt == 3){
					start = j+1;
					
					if(start == 10) start = 1;
					
					next_ining = true;
					
					break;
				}
			}
			
			if(next_ining) break;
			start = 1;
		}
	}
	
	ans = ans > score ? ans : score;
//	cout << ans << endl;
	
}
void dfs(int cnt){
	
	if(cnt == 10){
		//다골랐으니까 게임을 진행한다.
//		print();
		play();
		return; 
	}
	
	for(int i = 1; i <= 9; i++){
		if(visit[i]) continue;
		
		visit[i] = true;
		order[i] = cnt;
		dfs(cnt+1);
		visit[i] = false;
	}
}

int main(void) {
	cin >> N;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= 9; j++){
			cin >> arr[i][j];
		}
	}
	
//	4번타자는 이미 골라졌다.
	visit[4] = true;
//	4번타자는 1번선수이다. 
	order[4] = 1;
	
	dfs(2);
	
	cout << ans << endl;
	return 0;
}
