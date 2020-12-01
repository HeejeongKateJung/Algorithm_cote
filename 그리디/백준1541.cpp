#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
using namespace std;


int solution(string s){
	int answer = 0;
	string str_num = ""; 
	
	bool isMinus = false;
	
	for(int i = 0; i <= s.length(); i++){
		
		if(s[i] == '-' || s[i] == '+' || s[i] == '\0'){
			
			if(isMinus){
				answer-=stoi(str_num);
			}else{
				answer+=stoi(str_num);
			}
			
			str_num = "";
			
			
			//���� ���Ŀ��� ��𿡴ٰ� ��ȣ�� ġ�� ���� ������ ���ڸ���
			//���δ� ���ָ� �׳� �װ� �ּ��̴�. 
			if(s[i] == '-'){
				isMinus = true;
			}
			
		}
		
		
		//������ ���
		else{
			str_num+=s[i];
		}
		
		
	}
	
	
	return answer;
	
}

int main(void)
{
	string input;
	cin >> input;
	
	int ans = solution(input);
	
	cout << ans << endl;
	return 0;
}
