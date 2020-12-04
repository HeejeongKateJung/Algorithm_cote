#include <iostream>
using namespace std;

void pick(int[], int, int );

int main(void){
	
	int n, m;
	
	cin >> n >> m;
	
	int cand[n];
	
	for(int i = 0; i < n; i++){
		cin >> cand[i];
	}
	
	pick(cand, n, m);
	return 0;
}

void pick(int cand[], int n, int m){
	
	int start1, start2, result, max;
	
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			for(int k = 0; k < n; k++){
				
				if(i != j && j != k && i != k){
					result = cand[i] + cand[j] + cand[k];
					if(max < result && result <= m){
						max = result;
					}
				}	
				
			}	
		}
	}
	
	cout << max << endl;
}
