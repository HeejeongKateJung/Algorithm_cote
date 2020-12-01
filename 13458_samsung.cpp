#include <iostream>

using namespace std;

int numPlace, numMaster, numSubMaster;

//중요!! count 가 longlong 형이어야 함. 
long long count;

int main(void)
{

	cin >> numPlace;
	
	int maxPeople[numPlace];
	
	for(int i = 0; i < numPlace; i++){
		cin >> maxPeople[i];
	}
	
	cin >> numMaster >> numSubMaster;
	
	for(int i = 0; i < numPlace; i++){
		
		
		maxPeople[i]-=numMaster;
		count++;
		
		if(maxPeople[i] <= 0){
			continue;
		}
		
		
		int dummy = maxPeople[i]%numSubMaster;
		int subman = maxPeople[i]/numSubMaster;
		
		if(dummy != 0){
			count+=subman;
			count++;
		}else{
			count+=subman;
		}
		
	}
	

	
	cout << count;	
	
	
	return 0;
}
