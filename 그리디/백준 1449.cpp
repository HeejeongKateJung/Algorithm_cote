#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int N, L;
	vector<int> v;
	
	
	
	cin >> N >> L;
	
	if(N == 1){
		cout << 1 << endl;
		return 0;
	}
	
	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		v.push_back(a);
	}
	
	sort(v.begin(), v.end());
	
	
	int start = v[0];
	int cnt = 0;
	int i = 0;
	
	while(i < v.size()){
		i++;
//		cout << "i: " << i << endl;

		if(v[i]-start+1 > L){
			cnt++;
			start = v[i];
//			cout << "new start: " << start << endl;
//			cout << "count: " << cnt << endl;
		}
		
		if(i == v.size()-1){
			cnt++;
			break;
		}
		
		
	}
	
	cout << cnt << endl;
	
	return 0;
}


