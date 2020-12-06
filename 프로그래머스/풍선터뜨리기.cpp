#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

/**
���� ���, 7 - 6 - 4�� ���������� ���� �ִٸ� 6���� ū 7�� ���� ��Ʈ�� �� �ְ�,

��ȣ�� ���� 4�� ǳ���� 1���� ���� �����ؼ� 6�� ���ı��� ����� ���� �����ϴ�.

������, 3 - 6 - 4�� ���������� ���� �ִٸ� �� ���� ��ȣ�� 2�� ��Ʈ���� �����ؼ� ��Ģ�� ����ȴ�.

��, ������ �ּڰ��� �˸� ���ı��� ���� �� �ִ��� ���θ� �� �� �ִ�. 
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
