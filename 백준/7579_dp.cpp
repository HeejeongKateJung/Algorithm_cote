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
				
				//i��°�� ���� �� ���
				dp[j+c] = Max(dp[j+c], dp[j]+mem);
				
				//�ٷ� contV�� �߰����� �ʰ� temp���� �߰��ߴٰ�
				//for���� ������ contV�� �߰��� �ִ� ������
				//�ٷ� �߰��� ��� index 6 �� ���� �߰����� ��쿡
				//�װͿ� �ߺ��ؼ� index 6+c�� �Ǵٽ� �� ���ɼ��� �ֱ� ������.  
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
