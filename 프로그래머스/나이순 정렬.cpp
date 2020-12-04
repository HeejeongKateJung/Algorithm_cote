#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


bool cmp(pair<int,string>, pair<int, string>);
int main(void){
	
	int num;
	cin >> num;
	
	vector<pair<int, string> > v;
	
	v.resize(num);
	for(int i = 0; i < num; i++){
		cin >> v[i].first >> v[i].second;
	}
	
	stable_sort(v.begin(), v.end(), cmp);
	
	for(int i = 0; i < num; i++){
		cout << v[i].first << v[i].second << endl;
	}	
	
	
	
	return 0;
}

bool cmp(pair<int, string> a , pair<int, string> b){
	if(a.first < b.first)
	{
		return true;
	}else{
		return false;
	}
}
