#include <iostream>
#include <vector>

#define MAX 5
using namespace std;

/**
	순열과 조합의 차이점은 순서가 있냐 없냐의 차이이다.

조합에는 순서가 없기 때문에, 과거에 시작점으로 삼았던 친구는 다시는 쳐다도 보지 말라는 식으로 설명을 했었다.

하지만, 순열은?? 과거에 시작점으로 삼았던 친구를 다시 한번 쳐다봐줘야 한다.

조합 → { 1, 2, 3 } = { 2, 1, 3 } 이므로, 시작점이 2가 되는 순간 더 작은 요소인 1은 쳐다도 보지 말아라 !

순열 → { 1, 2, 3 } != { 2, 1, 3 } 이므로, 시작점이 2가 되더라도 더 작은 요소인 1을 쳐다봐야 한다 !

라는 차이가 있다.
*/


int arr[MAX];
bool visit[MAX];
vector<int> v;
void print(){
	for (int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

void dfs(int cnt) {
	if(cnt == 3){
		print();
		return;
	}
	
	//조합: for(int i = IDX; i < MAX; i++)
	//dfs(i, cnt) 
	for(int i = 0; i < MAX; i++){
		if(visit[i])	continue;
		visit[i] = true;
		v.push_back(arr[i]);
		dfs(cnt+1);
		v.pop_back();
		visit[i] = false;
	}
}


int main(void){
	
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5;
	
	dfs(0);
	return 0;
}
