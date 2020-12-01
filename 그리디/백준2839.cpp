#include <iostream>

using namespace std;

int main(void)
{
	
	int N;
	cin >> N;
	
	int num_5 = 0;
	int num_3 = 0;
	
	while(1)
	{
		if(N <= 0){
			break;
		}
		if(N%5==0){
			num_5++;
			N-=5;
		}
		else if(N%3==0){
			num_3++;
			N-=3;
		}
		else{
			if(N >= 5){
				num_5++;
				N-=5;
			}
			else{
				num_3++;
				N-=3;
			}
		}
		
	}
	int ans = 0;
	if(N == 0){
		ans = num_3+num_5;
	}else{
		ans = -1;
	}
	
	cout << ans << endl;
	
	return 0;
}
