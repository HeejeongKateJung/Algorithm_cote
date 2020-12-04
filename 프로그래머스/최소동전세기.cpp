#include <iostream>
using namespace std;



int main(void)
{

	int n, k;
	int result = 0; 
	
	cin >> n >> k;
	
	int value[n];
	
	for(int i = 0; i < n; i++)
	{
		cin >> value[i];
	}	
	
	for(int i = n-1; i >= 0; i--)
	{
		
		if(k%value[i] != k){
			int coin = k/value[i];
			result+=coin;
			
			k = k%value[i];
		}
		
		if(k == 0){
			break;
		}
	}
	
	cout << result << endl;
	
	return 0;
}
