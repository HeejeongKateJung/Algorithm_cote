#include <iostream>

using namespace std;

int n;
int check[1000001];

int comp[7] = {1000000, 100000, 10000, 1000, 100, 10, 1};

int numbers[7];

int main(void)
{
	cin >> n;
	int sum, num;
	
	for(int i = 1; i <= n; ++i){
		sum = 0;
		num = i;
		for(int j = 0; j < 7; j++){
			
			int composition = num/comp[j];
				
			sum+=composition;
			
			num = num%comp[j];
			
		}
		if(sum+i == n){
			cout << i << endl;
			return 0;
		}
		
	}
	
	cout << 0 << endl;
	return 0;
}
