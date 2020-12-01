#include <iostream>
#include <queue> 
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<pair<int,int> > input;

bool ascByStartTime(pair<int,int> a, pair<int,int> b){
	if(a.first == b.first){
		return a.second < b.second;
	}
	
	return a.first < b.first;
}

struct ascByEndTime{
	bool operator()(const pair<int, int> &a, const pair<int, int> &b){
		if(a.second==b.second){
			return a.first>b.first;
		}
		return a.second>b.second;
	}
};

int main(void)
{
	cin >> N;
	for(int i = 0; i < N; i++){
		int s, e;
		cin >> s >> e;
		input.push_back(make_pair(s, e));
	}

	priority_queue<pair<int,int>, vector<pair<int,int> >, ascByEndTime >  pq;
	
	sort(input.begin(), input.end(), ascByStartTime);
	pq.push(input[0]);
	
	int cnt = 1;
	for(int i = 1; i < input.size(); i++){
		
		if(pq.top().second <= input[i].first){
			pq.pop();
			pq.push(input[i]);
		}else{
			pq.push(input[i]);
			cnt++;
		}
		
	}
	
	cout << cnt << endl;
	


	return 0;
}
