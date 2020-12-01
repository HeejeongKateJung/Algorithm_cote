#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int,int> b){
	//���� �ð��� ������ ���� �ð��� ���� ������� 
	if(a.second == b.second){
		return a.first < b.first;
	}
	//����ð��� �ٸ��� ����ð��� ���� �������.. 
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
