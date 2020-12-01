#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b){
	return a > b;
}

int solution(int n, vector<int> v){
	
	sort(v.begin(), v.end(), compare);
	
	vector<int> maxWeight;
	
	int num_of_rope = 1;;
	
	for(int i = 0; i < n; i++){
		
		maxWeight.push_back(v[i]*num_of_rope);
		
		num_of_rope++;
	}
	
	sort(maxWeight.begin(), maxWeight.end(), compare);
	
	return maxWeight[0]; 
	
}

int main(void)
{
	int n;
	vector<int> v;
	cin >> n;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		v.push_back(a);
	}
	
	int ans = solution(n, v);
	
	cout << ans << endl;
	
	return 0;
}
