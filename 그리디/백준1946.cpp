#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//문제에서 input으로 주어지는 숫자들은
//""점수""가 아니라 ""순위""임을 잊지 말것. 

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
	
	//n^2 로는 해결되지 않음... (시간 초과) 
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

	//bound 라는 변수는 현재 검사한 사람의 최고 면접 점수이다.
	//서류점수가 현재 검사하는 사람의 서류점수보다 낮은 사람들은
	//면접점수가 이 면접점수 bound 순위보다 높아야 합격할 수 있다. 
	int bound = v[0].second;
	
	for(int i = 1; i < N; i++){
		int interview = v[i].second;
		
		//bound가 2등인데 니가 3등이면 넌 덜어짐. 
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
