#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    long long min = 1;
    long long max = (long long)times[times.size()-1]*n;
    answer = max;
    long long sum = 0;
    while(min <= max){
    	long long mid = (min+max)/2;
    	sum = 0;
    	for(int i = 0; i < times.size(); i++)
    		sum+=mid/times[i];
    	
    	if(n > sum){
    		min = mid+1;
		}else{
			answer = answer >= mid ? mid : answer;
			max = mid-1;
		}
    	
	}
	
	cout << answer << endl;
    
    return answer;
}

int main(void){
	solution(6, {2,20});
	return 0;
}
