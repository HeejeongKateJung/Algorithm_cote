#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> parent; 
bool cmp(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

/**
	그리디 알고리즘 -> Kruskal 알고리즘 사용
	union find 구현, 적용 
*/

int find(int x){
	//x == parent[x] // root 노 
	if(x == parent[x])	return x;
	else{
		int y = find(parent[x]);
		
		//x의 부모는 y로 바로 올려준다. 
		parent[x] = y;
		return y; 
	}
}

int isCycle(int x, int y){
	x = find(x);
	y = find(y);
	//부모가 같다는 뜻이므로 사이클이 존재한다. 
	if(x == y) return 1;
	else	return 0;
}

void unionn(int x, int y){
	x = find(x);
	y = find(y);
	
	//x와 y의 부모가 같지 않을때
	//작은 숫자를 parent 로 올려준다.
	if(x < y)	parent[y] = x;
	else	parent[x] = y; 
} 

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(), costs.end(), cmp);

	for(int i = 0; i < n; i++){
		parent.push_back(i);
	}
	
	for(int i = 0; i < costs.size(); i++){
		if(!isCycle(costs[i][0], costs[i][1])){
			answer+=costs[i][2];
			unionn(costs[i][0], costs[i][1]);
		}
	}
	cout << answer << endl;
    return answer;
}

int main(void){
	solution(4, {{0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8}});
	
	return 0;
}
