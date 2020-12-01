#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int memory[101], cost[101];
int dp[10001];
vector<int> contV;
vector<int> temp;
vector<int>::iterator ptr;

int Max(int x, int y){
	return x > y ? x : y;
} 

void func(){
	
	dp[0] = 0;
	dp[cost[0]] = memory[0];
	int mem, c;
	int limit = cost[0];
	contV.push_back(0);
	contV.push_back(cost[0]);
	
	
	for(int i = 1; i < N; i++){
		
		mem = memory[i];
		c = cost[i];
		
		for(int j = 0; j <= limit; j++){
			
			if(find(contV.begin(), contV.end(), j) != contV.end()){
				
				//i번째를 선택 할 경우
				dp[j+c] = Max(dp[j+c], dp[j]+mem);
				
				//바로 contV에 추가하지 않고 temp에다 추가했다가
				//for문이 끝나면 contV에 추가해 주는 이유는
				//바로 추가할 경우 index 6 에 값을 추가했을 경우에
				//그것에 중복해서 index 6+c에 또다시 할 가능성이 있기 때문임.  
				temp.push_back(j+c);
			}
			
		}
		
		limit += c;
		
		for(ptr = temp.begin(); ptr != temp.end(); ++ptr){
			contV.push_back(*ptr);
		}
		
		temp.clear();
	}
	
}

int main(void)
{
	
	cin >> N >> M;
	for(int i  = 0; i < N; i++){
		cin >> memory[i];
	}
	for(int i  = 0; i < N; i++){
		cin >> cost[i];
	}
	
	for(int i = 0; i < 10001; i++){
		dp[i] = -1;
	}
	
	func();
	
	for(int i = 0; i < 10001; i++){
		
		if(dp[i] >= M){
			cout << i << endl;
			break;
		}
	}
	
	
	
	return 0;
}
