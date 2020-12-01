#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//�������� input���� �־����� ���ڵ���
//""����""�� �ƴ϶� ""����""���� ���� ����. 

bool compare(pair<int, int> a, pair<int, int> b){
	if(a.first < b.first){
		return true;
	}
	return false;
}

int get_min(int a, int b){
	return a < b ? a : b;
} 

int solution(int N, vector<pair<int, int> > v){
	int cnt = N;
	sort(v.begin(), v.end(), compare);
	
	//n^2 �δ� �ذ���� ����... (�ð� �ʰ�) 
//	for(int i = 0; i < v.size(); i++){
//		int paper = v[i].first;
//		int interview = v[i].second;
//		
//		for(int j = i+1; j < v.size(); j++){
//			if(interview > v[j].second){
//				cnt_fail++;
//				break;
//			}
//		}
//		
//	}

	//bound ��� ������ ���� �˻��� ����� �ְ� ���� �����̴�.
	//���������� ���� �˻��ϴ� ����� ������������ ���� �������
	//���������� �� �������� bound �������� ���ƾ� �հ��� �� �ִ�. 
	int bound = v[0].second;
	
	for(int i = 1; i < N; i++){
		int interview = v[i].second;
		
		//bound�� 2���ε� �ϰ� 3���̸� �� ������. 
		if(bound < interview){
			cnt--;
		}
		bound = get_min(bound, interview);
		
	}
	
	return cnt;
	
	
}


int main(void)
{
	int T, N;
	vector<int> answer;
	
	
	cin >> T;
	for(int i = 0; i < T; i++){
		vector<pair<int,int> > v;
		cin >> N;
		for(int i = 0; i < N; i++){
			int a, b;
			cin >> a >> b;
			v.push_back(make_pair(a, b));
		}
		
		answer.push_back(solution(N, v));
	}
	
	for(int i = 0; i < T; i++){
		cout << answer[i] << endl;
	}
	

	return 0;
} 
