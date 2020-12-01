#include <iostream>

using namespace std;

int N;
int main(void)
{
	cin >> N;
	int jimin, hansu;
	cin >> jimin >> hansu;
	
	int bigger, smaller;
	bigger = jimin > hansu ? jimin : hansu;
	smaller = jimin < hansu ? jimin : hansu;
	
	if(bigger > N || smaller > N){
		cout << -1 << endl;
		return 0;
	}
	
	int round = 0;
	while(bigger != smaller){
		bigger = bigger/2 + bigger%2;
		smaller = smaller/2 + smaller%2;
		round++;
	}
	
	cout << round << endl;
	return 0;
}
