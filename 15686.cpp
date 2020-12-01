#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

int n, m, map[51][51], closed;

int temp[51][51];
int ans = 51*51;
bool visit[51*51];

vector<pair<int, int> > c;
vector<pair<int, int> > h;
vector<pair<int, int> > selected_c;

void print(){
	cout << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << temp[i][j] << " ";
		}
		cout << endl;
	}
	
}

void cal_dist(){

	
	int sum = 0;
	for(int i = 0; i < h.size(); i++){
		int chicken_dist = n*n;
		for(int j = 0; j < selected_c.size(); j++){
			
			int dist = abs(h[i].first - selected_c[j].first) + abs(h[i].second - selected_c[j].second);
			chicken_dist = chicken_dist < dist ? chicken_dist : dist;
		}
		sum+=chicken_dist;
	}
	
	ans = ans < sum ? ans : sum;
	
	return;
	
	
}

void close(int cnt, int idx){
	
	if (cnt == m){
		cal_dist();
		return;
	}
	
	for(int i = idx; i < c.size(); i++){
		
		if(visit[i])	continue;
		
		visit[i] = true;
		selected_c.push_back(c[i]);
		close(cnt+1, i);
		selected_c.pop_back();
		visit[i] = false;
	}
}
int main(void)
{
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> map[i][j];
			if(map[i][j] == 2)	c.push_back(make_pair(i, j));	
			
			if(map[i][j] == 1)	h.push_back(make_pair(i, j));
		}
	}
	
	close(0,0);
	cout << ans << endl;
	return 0;
}
