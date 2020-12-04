#include <iostream>

using namespace std;


int n;

int count[1000001];

int Min(int a, int b)
{
	if(a < b){
		return a;
	}else{
		return b;
	}
}

int main(void)
{
	cin >> n;
	
	count[n] = 0;
	
	count[1] = 0;
	count[2] = 1;
	count[3] = 1;
	
	for(int i = 2; i <= n; i++){
		count[i] = count[i-1] + 1;
		if(i%2 == 0){
			count[i] = Min(count[i], count[i/2]+1);
		}
		if(i%3 == 0){
			count[i] = Min(count[i], count[i/3]+1);
		}
	}
	
	cout << count[n] <<endl;
	
	
}
