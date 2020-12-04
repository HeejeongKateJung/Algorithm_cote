#include <iostream>
#include <vector>
using namespace std;

int n, count;
int map[101][101];
int visit[101];

void dfs(int node){
	
	//�ϴ� �� ���� �湮��. 
	visit[node] = 1;
	
	for(int i = 1; i <= n; i++){
		//���� ����Ǿ� �ְ�, �湮�� ���� �ֵ��� ã�Ƽ� 
		if(visit[i] == 0 && map[node][i] == 1){
			//�³׸� �湮�ߴٰ� ǥ���ϰ� 
			count++;
			
			//�³׿��� ����� �ֵ��� �� ã�´�. 
			dfs(i);
		}
	}
}

int main(void)
{	
	cin >> n;
	int link;
	cin >> link;
	
	for(int i = 0; i < link; i++){
		int first, second;
		cin >> first >> second;
		map[first][second] = map[second][first] = 1;
	}
	
	dfs(1);
	 
	cout << count << endl;
	
	return 0;
}
