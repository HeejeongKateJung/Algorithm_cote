#include <iostream>
#include <vector>
#include <algorithm>
#include <queue> 
using namespace std;

bool comp(pair<int, int> a, pair<int,int> b){
	if(a.second != b.second){
		return a.second < b.second;
	}
	
	return a.first < b.first;
}

int solution(int N, int M, vector<pair<int, int> > v){
	
	sort(v.begin(), v.end(), comp);
//	for(int i = 0; i < v.size(); i++){
//		cout << v[i].first << " " << v[i].second << endl;
//	}
	int ans = 0;
	
	vector<int> taken(N);
	
	for(int i = 0; i < v.size(); i++){
		
		for(int j = v[i].first; j <= v[i].second; j++){
			if(taken[j] == 0){
				ans++;
				taken[j] = 1;
				break;
			}
		}
		
	}
	
	return ans;
}

int main(void)
{
	int testcase;
	cin >> testcase;
	for(int i = 0; i < testcase; i++){
		
		int N, M;
		vector<pair<int, int> > v;
		cin >> N >> M;
		for(int j = 0; j < M; j++){
			int a, b;
			cin >> a >> b;
			v.push_back(make_pair(a, b));
		}
		
		int ans = solution(N, M, v);
		cout << ans << endl;
	}
	
	return 0;
}
