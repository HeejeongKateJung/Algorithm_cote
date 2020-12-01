#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int,int> b){
	//종료 시간이 같으면 시작 시간이 빠른 순서대로 
	if(a.second == b.second){
		return a.first < b.first;
	}
	//종료시간이 다르면 종료시간이 빠른 순서대로.. 
	else{
		return a.second < b.second;
	}
}

int solution(int n, vector<pair<int, int> > meetings){
	
	sort(meetings.begin(), meetings.end(), compare);
	
	int now = meetings[0].second;
	int count = 1;
	
	for(int i = 1; i < meetings.size(); i++){
		if(now <= meetings[i].first){
			count++;
			now = meetings[i].second;
		}
	}
	
	return count;
	
}


int main(void){
	
	int n;
	vector<pair<int, int> > meetings;
	cin >> n;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		meetings.push_back(make_pair(a, b));
	}
	
	int answer = solution(n, meetings);
	
	cout << answer << endl;
	
	
} 
