#include <iostream>
#include <string>
using namespace std;

int n;


int main(void)
{
	cin >> n;
	
	int number = 665;
	int count = 0;
	while(count < n){
		
		number++;
		if(to_string(number).find("666") != -1){
			count++;
		}
	}
	
	cout << number << endl;
	
	
	
	
	return 0;
}
