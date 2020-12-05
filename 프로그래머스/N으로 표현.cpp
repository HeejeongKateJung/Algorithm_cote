#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <set>

using namespace std;

// void print()

int solution(int N, int number) {
    int answer = -1;
    vector<set<int> > v(10);
    int NN = 0;
    for(int i = 0; i < 9; i++){
    	v[i].insert(NN);
    	NN = NN*10+N;
	}
    
    for(int i = 0; i < 9; i++){
    	for(int j = 0; j < 9; j++){
    		if(i+j >= 9)	continue;
    		
    		for(auto r : v[i]){
    			for(auto l : v[j]){
    				v[i+j].insert(l+r);
    				v[i+j].insert(l-r);
					v[i+j].insert(l*r);
					if(r != 0)	v[i+j].insert(l/r);
				}
			}
		}
		
		if(v[i].find(number) != v[i].end())	return i;
	}
    
    return -1;
}

//  int main(void){
//  	cout << solution(2, 11);
//  	return 0;
//  }
