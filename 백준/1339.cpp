#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;
int N;
vector<string> v;

bool cmp(string a, string b){
	return a.length() > b.length() ? true : false;
}

bool cmp_value(pair<char,int> a, pair<char, int> b){
	if(a.second == b.second) return a.first > b.first;
	
	return a.second > b.second;
}

int main(void)
{
	int ans = 0;
	cin >> N;
	for(int i = 0; i < N; i++){
		string s;
		cin >> s;
		v.push_back(s);
	}
	
	map<char, int> m;
	
	for(string s : v){
//		cout << s << endl;
		for(int i = 0; i < s.length(); i++){
//			cout << s[i] << " ";
			if(m.find(s[i]) == m.end()){
				m.insert(make_pair(s[i],pow(10,(s.length()-1-i)) ));
			}
			else{
				m[s[i]] = m[s[i]]+pow(10,(s.length()-1-i));	
			}
			
			
		}
		
	}
	
	vector<pair<char,int> > nv(m.begin(), m.end() );
	
	sort(nv.begin(), nv.end(), cmp_value);

	vector<pair<char,int> >::iterator iter;
	
	int value = 9;
	
	for(int i = 0; i < nv.size(); i++){
		ans+=(nv[i].second)*value;
		value--;
	}
	
	cout << ans;
	
	return 0;
}
