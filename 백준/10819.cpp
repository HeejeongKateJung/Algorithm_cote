#include <iostream>
#include <algorithm>
using namespace std;
int N, arr[9];


int main(void)
{
	cin >> N;
	
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
	
	sort(arr, arr+N);
	int answer = 0;
	do {
		int tmp = 0;
		for(int i = 0; i < N-1; i++){
			tmp+=(abs(arr[i]-arr[i+1]));
		}
		if(tmp > answer)	answer = tmp;
	} while(next_permutation(arr, arr+N));
	
	cout << answer << endl;
	return 0;
}
