#include <iostream>
#include <string>
using namespace std;

int Max(int x, int y){
	return x > y ? x : y;
} 

int main(void)
{
	string str1, str2;
	
	cin >> str1;
	cin >> str2;
	
	str1 = "0" + str1;
	str2 = "0" + str2;
	
	int lenStr1, lenStr2;
	
	lenStr1 = str1.length();
	lenStr2 = str2.length();
	
	
	
	//lcsTable 의 str0 부분을 모두 0으로 채워준다. 
	int lcsTable[lenStr2][lenStr1];
	
	for(int i = 0; i < lenStr2; i++){
		lcsTable[i][0] = 0;
	}
	
	for(int i = 0; i < lenStr1; i++){
		lcsTable[0][i] = 0;
	}
	
	
	for(int i = 1; i < lenStr2; i++){
		
		for(int j = 1; j < lenStr1; j++){
			
			
			if(str2[i] == str1[j]){
				lcsTable[i][j] = lcsTable[i-1][j-1] + 1;
			}
			
			else{
				lcsTable[i][j] = Max(lcsTable[i-1][j], lcsTable[i][j-1]);
			}
		}
	}
	
	
//	for(int i = 0; i < lenStr2; i++){
//		for(int j = 0; j < lenStr1; j++){
//			
//			cout << lcsTable[i][j] << " ";
//		}
//		
//		cout << endl;
//	}
	
	cout << lcsTable[lenStr2-1][lenStr1-1];
	
	
	return 0;
}
