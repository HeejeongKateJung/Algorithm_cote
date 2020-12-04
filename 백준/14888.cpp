#include <iostream>
#include <vector>
using namespace std;

int N;

// 0: + , 1: - , 2: *, 3: %
vector<int> oper;
vector<int> nums;


void 



int main(void)
{
	cin >> N;
	
	for(int i = 0; i < N; i++){
		int n;
		cin >> n;
		nums.push_back(n);
	}
	
	vector<int> opers;
	for(int i = 0; i < 4; i++){
		int n;
		cin >> n;
		opers.push_back(n);
	}
	
	for(int i = 0; i < 4; i++){
		for (int j = 0; j < opers[i]; j++){
			oper.push_back(i);
		}
	}
	
	for(int i = 0; i < oper.size(); i++){
		cout << oper[i] <<" ";
	}
	
	dfs(0);
	

	return 0;
}
