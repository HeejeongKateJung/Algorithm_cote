#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int N, map[21][21];
vector<int> picked;
int ans = 99999999;

void pick(int cnt){
	
	while(!picked.empty()){
		int member = picked.back();
		picked.pop_back();
		
		
		if(ans > dif){
			ans = dif;
			return;
		}
		
		return;
	}
}



int main(void)
{
	cin >> N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> map[i][j];
		}
	}
	
	
	
	
	return 0;
}
