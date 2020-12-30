#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int> > cost;
vector<bool> visit(10, false);
int answer = 99999999;


void dfs(int start, int cur, int cnt, int sum){
	
	//원래 위치로 돌아왔다면 리턴 
	if(cnt == N && cur == start){
		if(answer > sum)	answer = sum;
		return;
	}
	
	for(int i = 0; i < N; i++){
		// 자기 자신이거나 다음 도시로 이동할 방법이 없는 경우
		if(visit[cur] || cost[cur][i] <= 0)	continue;
		visit[cur] = true;
		
		// 이미 다음 예상 cost 가 현재 최솟값보다 커진다면 더이상 볼 필요가 없다. 
		if(sum+cost[cur][i] <= answer){
			dfs(start, i, cnt+1, sum+cost[cur][i]);
		}
		
		visit[cur] = false;
	}
}

int main(void)
{
	cin >> N;
	for(int i = 0; i < N; i++){
		vector<int> v;
		for(int j = 0; j < N; j++){
			int x;
			cin >> x;
			v.push_back(x);
		}
		cost.push_back(v);
	}
	
	
	for(int i = 0; i < N; i++){
		dfs(i, i, 0, 0);
	}
	
	cout << answer << endl;
	return 0;
}
