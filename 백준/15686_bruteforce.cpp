#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int map[51][51];
int N, numChicken;

pair<int, int> chicken[51*51];
pair<int, int> house[51*51];

int resultMin = 1000000000;

int getChickenDistance(vector<pair<int,int> > temp, int h){
	int realMin = 0;
	for(int i = 0; i < h; i++){
		int result = 10000000;
		
		int hx = house[i].first;
		int hy = house[i].second;
		
		for(int j = 0; j < numChicken; j++){
			int cx = temp.pop_back.first;
			int cy = temp.pop_back.second;
			
			int d = abs(hx-cx) + abs(hy-cy);
			if(result > d){
				result = d;
			}
			
		}
		realMin+=result;
	}
	return realMin;
}

void pick(pair<int,int> chicken[], int n, int r, int i, vector<pair<int,int> > temp, int h){
	
	if(r == 0){
		//모두 선택되었으므로 temp에 있는 원소로 치킨거리를 구한다.
//		cout << "선택된 chicken집: "; 
//		for(int i = 0; i < numChicken; i++){
//			cout << temp[i].first << " " << temp[i].second <<endl;
//		}
		
		int chickenDistance = getChickenDistance(temp, h);
		if(resultMin > chickenDistance){
			resultMin = chickenDistance;
		}
		return;
	}else if(i == n){
		return;
	}else{
//		temp[n-1-r] = chicken[i];
		temp.push_back(chicken[i]);
		pick(chicken, n, r-1, i+1, temp, h);
		pick(chicken, n, r, i+1, temp, h);
	}
	
}


int main(void)
{
	cin >> N >> numChicken;
	vector<pair<int,int> > picked;
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cin >> map[i][j];
		}
	}
	
	int c = 0, h = 0;
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			if(map[i][j] == 1){
				house[h] = make_pair(i, j);
				h++;
			}
			else if(map[i][j] == 2){
				chicken[c] = make_pair(i, j);
				c++;
			}
		}
	}
	
	
	pick(chicken, c, numChicken, 0, picked, h);
	
	cout << resultMin;
	
	
	
	
	return 0;
}
