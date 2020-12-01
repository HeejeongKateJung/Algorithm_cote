#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(int T){
	
	vector<int> v;
	v.push_back(0);
	v.push_back(0);
	v.push_back(0);
	v.push_back(0);
	while(T >= 10){
		
		if(T/300 > 0){
			v[0] = T/300;
			T=T%300;
		}
		else if(T/60 > 0){
			v[1] = T/60;
			T=T%60;
		}
		else if(T/10 > 0){
			v[2] = T/10;
			T=T%10;
		}
	}
	
	if(T != 0){
		v[3] = -1;
	}
	
	return v;
}

int main(void)
{
	int T;
	cin >> T;
	
	vector<int> v = solution(T);
	
	if(v[3] != 0){
		cout << -1 << endl;
	}
	else{
		for(int i = 0; i < 3; i++){
			cout << v[i] << " ";
		}
	}
	
	return 0;
}
