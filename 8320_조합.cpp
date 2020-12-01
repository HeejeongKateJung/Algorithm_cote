#include <iostream>

using namespace std;

int N, ans = 0;

int main(void)
{
	cin >> N;
	ans+=N;
	
	int count = 0, garo = 2;
	while(garo <= N) {
		bool flag = false;
		for(int sero = garo; sero*garo <= N; sero++){
			flag = true;
			ans++;
		}
		
		if(!flag) break;
		
		garo++;
		
		
	}
	
	cout << ans << endl;
		
	return 0;
}
