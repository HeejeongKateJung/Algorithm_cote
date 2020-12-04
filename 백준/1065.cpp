#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int N;
int main(void)
{
	int ans = 0;
	cin >> N;
	
	if(N < 100){
		cout << N << endl;
		return 0;
	}
	ans+=99;
	for(int i = 100; i <= N; i++){
		
		string s = to_string(i);
		
		int dif = (s[0]-'0')-(s[1]-'0');
		bool flag = false;
		for(int j = 1; j < s.length()-1; j++){
			int num1 = s[j]-'0';
			int num2 = s[j+1]-'0';
			
			if(dif != num1-num2){
				flag = true;
				break;
			}
		}
		
		if(!flag) ans++;
		
	}
	cout << ans;
	return 0;
}
