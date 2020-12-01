#include <iostream>
#include <vector>
#include <queue>
#define MAX 17
using namespace std;

int N, Map[MAX][MAX];
int count[MAX][MAX];

//direction[가로:0, 대각선:1, 세로:2][]
int dx[3][3] = {1,1,0,1,1,0,0,1,0};
int dy[3][3] = {0,1,0,0,1,1,0,1,1};


int main(void)
{
	cin >> N;
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cin >> Map[i][j];
		}
	}
	
	queue<pair<int,int> > q;
	
	q.push_back(make_pair(1,2))
	while(!q.empty()){
		
	}
	
	
	return 0;
}
