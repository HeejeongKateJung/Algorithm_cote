#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	string me, doc;
	cin >> me >> doc;
	
	if(me.length() >= doc.length()){
		cout << "go" << endl;
	}else{
		cout << "no" << endl;
	}
	
	return 0;
 } 
