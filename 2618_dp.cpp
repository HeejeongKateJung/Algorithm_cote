#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int N, W;
int map[1001][1001];
int dp[2][1001][1001];

int answer = 0;
int whichP[1001];

struct Police{
	int cX;
	int cY;
};

int getDistance(int posX, int posY, Police car){
	return (posX-car.cX)+(posY-car.cY);
}

int Min(int x, int y){
	return x < y ? x : y;
}

int main(void)
{	
	cin >> N >> W;
	vector<pair<int, int> > problem(W);	
	
	for(int i = 0; i < W; i++)
	{
		cin >> problem[i].first >> problem[i].second;
	}
	
	
		
	
	
	
	
	cout << answer << endl; 
	for(int i = 0; i < W; i++){
		cout << whichP[i] << endl;
	}
	
	return 0;
}
