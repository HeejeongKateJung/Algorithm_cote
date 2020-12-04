#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

vector<bool> btns(10, false);

int dst;

bool check(int now){
	string s = to_string(now);
	for(int i = 0; i < s.length(); i++){
		if(btns[s[i]-48]){
			return false;
		}
	}
	
	return true;

}

int main(void)
{
	int dst, c;
	cin >> dst;
	cin >> c;
	for(int i = 0; i < c; i++){
		int tmp;
		cin >> tmp;
		btns[tmp] = true;
	}
	
	string s = to_string(dst);
	
	int m = abs(dst-100);
	for(int i = 0; i <= 1000000; i++){
		
		if(check(i)){
			int tmp = abs(dst-i)+to_string(i).length();
			m = m < tmp ? m : tmp;
		}
		
	}
	
	cout << m << endl;

	return 0;
}



