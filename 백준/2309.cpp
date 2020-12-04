#include <iostream>
#include <vector>
#include <algorithm>
#define N 9
using namespace std;

vector<int> dwarfs;
vector<int> real;
bool visit[9];

void check(){
	int sum = 0;
	for(int i = 0; i < 7; i++){
		sum+=real[i];
	}
	
	if(sum == 100){
		sort(real.begin(), real.end());
		for(int i = 0; i < 7; i++){
			cout << real[i] << endl;
		}
	}
}
void select(int cnt, int idx){
	
	if(cnt == 7){
		
		check();
		
		return;
	}
	
	for(int i = idx; i < N; i++){
		
		if(visit[i])	continue;
		visit[i] = true;
		real.push_back(dwarfs[i]);
		select(cnt+1, i);
		real.pop_back();
		visit[i] = false;
	}
	
}

int main(void)
{
	for (int i = 0; i < N; i++){
		int h;
		cin >> h;
		dwarfs.push_back(h);
	}	
	
	select(0, 0);
	return 0;
}
