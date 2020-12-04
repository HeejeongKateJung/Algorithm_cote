#include <iostream>
using namespace std;

int factorial(int n)
{
	if(n == 0){
		return 1;
	}
	if(n == 1){
		return 1;
	}else{
		return n*factorial(n-1);	
	}
	
}

int main(void)
{
	
	int n, result;
	
	cin >> n;
	result = factorial(n);
	
	
	cout << result << endl;
	return 0;
}
