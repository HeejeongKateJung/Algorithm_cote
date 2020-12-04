#include <iostream>

using namespace std;
int N, K, count;

void dfs(int number, int idx) {
	
	if(idx > K) {
		count++;
		return;
	}
	if(number > N) {
		return;
	}
	
	dfs(number+1, idx+1);
	dfs(number+1, idx);
}

int main(void) {
	cin >> N >> K;
	dfs(1,1);
	cout << count << endl; 
	return 0;
}
