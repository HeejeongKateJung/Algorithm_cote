#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

pair<int, int> map[11][11];		//<���� ����� ��, �߰� ��� ����> 

vector<int> tree[11][11];		//������ ���� ������ ����մ� queue �� �迭�̴�. 

int dead[11][11];

int N;
int result;

int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void springAndSummer(){
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			//������ ������ �������� 
			if(tree[i][j].empty()){
				continue;	
			}
			
			for(int k = 0; k < tree[i][j].size(); k++){
				
				//���� ���̰� ��к��� ������ ���̱� 
				if(tree[i][j][k] > map[i][j].first){
					
					//k��° �������� ����� ���ڶ�ٸ� �� �ڿ��ִ� �ֵ� ���� ���δ�. 
					
					for(int l = tree[i][j].size()-1; l >= k; l--){
						dead[i][j]+=tree[i][j][l]/2;
						tree[i][j].pop_back();
						result--;
					}
					
					break;
				}
				//���� ���̰� ��к��� ������ �Կ��� ���̸� up��Ų��. 
				else{
					map[i][j].first -= tree[i][j][k];
					tree[i][j][k]++;
				}
			}

			
		}
	}
	
}

void autumn(){
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			for(int k = 0; k < tree[i][j].size(); k++){
				if(tree[i][j][k]%5 != 0){
					continue;
				}
				
				//���� 8ĭ�� ���� 1 �� ������ �ִ´�.
				for(int l = 0; l < 8; l++){
					int ny = i+dy[l];
					int nx = j+dx[l];
					
					if(ny > N || nx > N || ny < 1 || nx < 1){
						continue;
					}
					
					tree[ny][nx].push_back(1);
					result++;
				} 
			}
		}
	}
	
}

void winter(){
	for(int i = 1; i <= N; i++){
		for(int j = 1; j<=N; j++){
			map[i][j].first+=map[i][j].second;
		}
	}
}

int main(void)
{
	int numTree, time;
	cin >> N >> numTree >> time;
	
	result = numTree;
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			map[i][j].first = 5;
			cin >> map[i][j].second;
		}
	}
	
	for(int i = 0; i < numTree; i++){
		int y, x, age;
		cin >> y >> x >> age;
		tree[y][x].push_back(age);
	}

	
	
	for(int year = 0; year < time; year++){
		
		//�ʱ�ȭ
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				
				//� �������� �Ե��� �ʱ�ȭ 
				sort(tree[i][j].begin(), tree[i][j].end());
				map[i][j].first+=dead[i][j];
				dead[i][j] = 0;
				
				
			}
		}
		springAndSummer();
		autumn();
		winter();
		
	}
	
	cout << result;
	
	return 0;
}
