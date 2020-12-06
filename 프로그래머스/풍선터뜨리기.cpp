#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

/**
예를 들어, 7 - 6 - 4가 최종적으로 남아 있다면 6보다 큰 7은 먼저 터트릴 수 있고,

번호가 작은 4번 풍선도 1번은 제거 가능해서 6을 최후까지 남기는 것이 가능하다.

하지만, 3 - 6 - 4가 최종적으로 남아 있다면 더 작은 번호를 2번 터트려야 가능해서 규칙에 위배된다.

즉, 양쪽의 최솟값을 알면 최후까지 남길 수 있는지 여부를 알 수 있다. 
*/
int solution(vector<int> a) {
    int answer = 0;
    
    int min = a[0];
    vector<int> left(a.size());
    vector<int> right(a.size());
	for(int i = 0; i < a.size(); i++){
    	if(min > a[i])	min = a[i];
    	left[i] = min;
	}
	
	min = a[a.size()-1];
	
	for(int i = a.size()-1; i >= 0; i--){
		if(min > a[i])	min = a[i];
		right[i] = min;
	}
	
	for(int i = 0; i < a.size(); i++){
		if(a[i] > left[i] && a[i] > right[i])	continue;
		answer++;
	}
    
    cout << answer << endl;
    return answer;
}

int main(void){
	vector<int> a = {-16,27,65,-2,58,-92,-71,-68,-61,-33};
	vector<int> b = {1,2,3,4,5};
	solution(a);
	return 0;
} 
