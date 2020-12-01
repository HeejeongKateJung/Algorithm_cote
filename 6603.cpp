#include <iostream>
#include <vector>

using namespace std;
int k;
vector<int> nums;
vector<int> v;
bool visit[14];
void print(){
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
	return;
}
void select(int cnt, int idx){
	
	if(cnt == 6){
		print();
		return;
	}
	
	for(int i = idx; i < nums.size(); i++){
		if(visit[i])	continue;
		
		visit[i] = true;
		v.push_back(nums[i]);
		select(cnt+1, i);
		v.pop_back();
		visit[i] = false;
	}
	
	
}
void solution(){
	select(0,0);
}
int main(void)
{

	while(true){
		
		cin >> k;
		
		if(k == 0){
			break;
			return 0;
		}
		
		for(int i = 0; i < k; i++){
			int n;
			cin >> n;
			nums.push_back(n);
		}
		solution();
		cout << endl;
		
		v.clear();
		nums.clear();
		for(int i = 0; i < k; i++){
			visit[i] = false;
		}
	}
	
	return 0;
}
