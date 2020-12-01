#include <iostream>
#include <vector>
#include <string>
using namespace std;

int solution(int N, string s){
	int num_L = 0;
	int holder = 1;
	for(int i = 0; i < s.length(); i++){
		
		
		if(s[i] == 'S'){
			holder++;
		}else{
			num_L++;
			if(num_L == 2){
				num_L = 0;
				holder++;
			}
		}
		
	}
	
	if(holder >= N){
		return N;
	}else{
		return holder;
	}
	
//	return holder; 
}

int main(void){
	int N;
	string s;

	cin >> N >> s;
	
	int ans = solution(N, s);
	cout << ans << endl;
	return 0;
}

