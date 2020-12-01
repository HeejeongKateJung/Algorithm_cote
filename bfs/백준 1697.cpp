#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 100000
using namespace std;

int N, K;
int cnt[MAX+1];

queue<int> q;

int np[3] = {-1, 1, 2};

int getMin(int a, int b){
	return a < b ? a : b;
}

void bfs(int node){
	q.push(node);
	cnt[node] = 0;
	
	while(!q.empty()){
		int pos = q.front();
		q.pop();
		
		if(pos == K){
			return;
		}
		
		for(int i = 0; i < 3; i++){
			//next postion을 구한다. 
			int next = pos+np[i];
			if(i == 2){
				next = pos*np[i];
			}
			
			if(next < 0 || next > MAX || cnt[next] != 0){
				continue;
			}
			

			cnt[next] = cnt[pos]+1;
			q.push(next);
			
		}
	}
	
	
}

int main(void)
{
	cin >> N >> K;
	
	bfs(N);
	cout << cnt[K] << endl;
	return 0;
}
