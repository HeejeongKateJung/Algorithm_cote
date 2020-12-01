#include <iostream>
#include <vector>

using namespace std;

int main(void){
	
	int L = 5, P = 4, V = 4;
	vector<int> answer;
	while(1){
		int ans = 0;
		cin >> L >> P >> V;
		
		if(L == 0 && P == 0 && V == 0){
			break;
		}
		
		int circle = V/P;
		int left = V%P;
		ans+=circle*L;
		
		if(left >= L){
			ans+=L;
		}else{
			ans+=left;
		}
		ans+=left;
		answer.push_back(ans);
		
		
	}
	
	for(int i = 0; i < answer.size(); i++){
		cout << "Case " << i+1 << ": " << answer[i] << endl;
	}
	
	
	
	return 0;
}
