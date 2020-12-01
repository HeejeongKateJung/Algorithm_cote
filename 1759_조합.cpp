#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int L, C;
char arr[15];

void backTracking(int pos, string str, int ja, int mo) {
	if(str.size() == L){
		//자음과 모음의 여부를 검사하고 조건에 맞으면 출력한다. 
		if(ja < 2 || mo < 1) return;
		
		cout << str << endl;
		return; 
	}
	
	//1. str 크기가 n이 될때까지 첫 시작부터 해서 그다음 str을 순차적으로 담는다. 
	for(int i = pos; i < C; i++){
		if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u'){
			backTracking(i+1, str+arr[i], ja, mo+1);
		}else{
			backTracking(i+1, str+arr[i], ja+1, mo);
		}
	}
}
int main(void)
{
	cin >> L >> C;
	for(int i = 0; i < C; i++){
		cin >> arr[i];
	}
	
	sort(arr, arr+C);
	
	backTracking(0,"",0,0);
	
	return 0;
}

