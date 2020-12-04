#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	
	int arr[n];

	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	sort(arr, arr+n);

	int result = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i; j++){
			result += arr[j];
		}
	}
	
	cout << result << endl;
	return 0;
}
