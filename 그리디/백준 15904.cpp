#include <iostream>
#include <queue>
#include <string> 

using namespace std;

string solution(string s){
	string result = "";
	queue<char> ucpc;
	ucpc.push('U');
	ucpc.push('C');
	ucpc.push('P');
	ucpc.push('C');
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == ucpc.front()){
			ucpc.pop();
			result+=s[i];
		}
		
	}
	
//	cout << result << endl;
	
	if(result == "UCPC"){
		return "I love UCPC";
	}else{
		return "I hate UCPC";
	}
	
}

int main(void)
{
	string s;
	
	getline(cin, s);
	
	
	string result = solution(s);
	
	cout << result << endl;	
	return 0;
}
