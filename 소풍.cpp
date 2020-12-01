#include <iostream>
#include <fstream>
using namespace std;

int n;
bool areFriends[10][10];


int countPairings(bool taken[10]) {
	bool finished = true;
	for(int i = 0; i < n; ++i){
		cout << taken[i] << endl;
		if(!taken[i])
			finished = false;
	}
		
	if(finished)
		return 1;
	int ret = 0;
	
	for(int i = 0; i < n; ++i){
		for(int j = 0 ; j < n; ++i){
			if(!taken[i] && !taken[j] && areFriends[i][j]){
				taken[i] = taken[j] = true;
				ret += countPairings(taken);
				taken[i] = taken[j] = false;
			}
		}
	}
	
	return ret;
}

int main(void){
	
	
	bool taken[10];
	
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			areFriends[i][j] = false;
		}
		
		taken[i] = false;
	}
	
	
	
	int ret = countPairings(taken);
	
	cout << ret << endl;
	
	return 0;
	
}
