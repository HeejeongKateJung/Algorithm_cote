#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int N;
	vector<int> scores;
	
	cin >> N;
	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		scores.push_back(a);
	}
	
	reverse(scores.begin(), scores.end());
	
	int ans = 0;
	
	for(int i = 0; i < scores.size(); i++){
		
		if(scores[i] <= scores[i+1]){
			int before = scores[i+1];
			scores[i+1] = scores[i]-1;
			ans+=(before-scores[i+1]);
		}
	}
	
	cout << ans;
	
	return 0;
}
