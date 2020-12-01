#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//내림차순 
bool naerim_comp(int a, int b){
	if(a > b){
		return true;
	}
	return false;
}

//오름차순 
bool orum_comp(int a, int b){
	if(a < b){
		return true;
	}
	return false;
}

int get_max(int a, int b){
	if(a > b){
		return a;
	}else{
		return b;
	}
}

int solution(int N, int ans, vector<int> positive, vector<int> negative){
	
	//양수는 내림차순, 음수는 오름차순 정렬
	sort(positive.begin(), positive.end(), naerim_comp);
	sort(negative.begin(), negative.end(), orum_comp); 
	
	vector<int>::iterator it;
	it = positive.begin();
	
	if(positive.size()%2 != 0){
		ans+=positive[positive.size()-1];
		positive.pop_back();
		
	}
	
	while(it < positive.end()){
		
		int a = *it;
		int b = *(it+1);
		
		ans+=(a*b);
		
		it+=2;
	}
	
	if(negative.size()%2 != 0){
		ans+=negative[negative.size()-1];
		negative.pop_back();
	}
	
	it = negative.begin();
	while(it < negative.end()){
		int a = *it;
		int b = *(it+1);
		
		ans+=(a*b);
		
		it+=2;
	}
	

	
	
	return ans;
	
	
}




int main(void)
{
	int N;
	vector<int> positive;
	vector<int> negative;
	int ans = 0;
	cin >> N;
	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		if(a == 1){
			ans+=a;
		}
		else if(a > 1){
			positive.push_back(a);
		}
		else if(a < 1){
			negative.push_back(a);
		}
	}
	
	
	ans = solution(N, ans, positive, negative);
	cout << ans << endl;
	return 0;
}
