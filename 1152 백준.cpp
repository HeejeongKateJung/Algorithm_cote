#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(void)
{
	string s, bomb;
	cin >> s >> bomb;
	queue<char> candidate;
	string next = "";
	int b_idx = 0;
	
	bool isBomb = true;
	while(isBomb){
		string temp = "";
		for(int i = 0; i < next.length(); i++){
			
			char c = next[i];
			if(c != bomb[0] && candidate.empty()){
				temp+=c;
				continue;
			}
			
			if(c == bomb[0]){
				candidate.push(c);
			}
			
		}
		
	}
	
	return 0;
}

//int main(void)
//{
//	string s, bomb;
//	string next;
//	
//	
//	cin >> s >> bomb;
//	next = s;
//	
//	bool isBomb = true;
//	while(isBomb){
//		isBomb = false;
//		string cand;
//		string temp = "";
//		for(int i = 0; i < next.length(); i++){
//			cout << "next[i]: " << next[i] << endl;
//			cand+=next[i];
//			
//			if(cand.length() == bomb.length()){
//				cout << "cand: " << cand << endl;
//				if(cand == bomb){
//					cand = "";
//					isBomb = true;
//					continue;
//				}
//				
//				temp+=cand;
//				cand = "";
//			}
//			
//			cout << "temp: " << temp << endl;
//		}
//		
//		
//		if(cand != ""){
//			temp+=cand;
//		}
//		
//		next = temp;
//		
//		cout << next << endl << endl;
//		
//		
//	}
//	cout << next << endl;
//	
//	return 0;
// } 

