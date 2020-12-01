#include <iostream>
#include <vector>
#include <algorithm>
#include <queue> 
using namespace std;

long solution(int n, int m, priority_queue<long, vector<long>, greater<long> > cards){
	
	long result = 0;
	
	for(int i = 0; i < m; i++){
		long x = cards.top();
		cards.pop();
		long y = cards.top();
		cards.pop();
		long next = x + y;
		cards.push(next);
		cards.push(next);
	}
	
	for(int i = 0; i < n; i++){
		result+=cards.top();
		cards.pop();
	}
	
	
	return result;
}

int main(void)
{
	int n, m;
	priority_queue<long, vector<long>, greater<long> > cards;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		cards.push(a);
	}
	
	long ans = solution(n, m, cards);
	cout << ans << endl;
	return 0;
}
