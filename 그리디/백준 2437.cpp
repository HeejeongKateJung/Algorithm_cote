#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(int a, int b){
	return a < b ? true : false;
}

int main(void){
	
	int N;
	vector<int> w;
	cin >> N;
	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		w.push_back(a);
	}
	
	sort(w.begin(), w.end(), comp);
	
	int sum = 0;
	
	int ans = 0;
	
	for(int i = 0; i < w.size(); i++){
		if(sum+1 < w[i]){
			break;
		}
		sum+=w[i];
	}
	
	cout << sum+1 << endl;
	
	
	
	return 0;
}
