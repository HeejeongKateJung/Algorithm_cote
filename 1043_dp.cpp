#include <iostream>
#include <queue>
using namespace std;

int N, M;		//���, ��Ƽ �� 
int revealed;	//������ �ƴ� ����� ��
int revealedPeople[51];
int Map[51][51];

queue<int> q;


int participated;	//��Ƽ�� ������ ��� ��

int count;

				//�������� �ϴ� ��Ƽ: false
				//���������ؾ� �ϴ� ��Ƽ: TRUE 
bool revealedParty[51];
bool relatedParty[51];


int main(void)
{
	cin >> N >> M;
	cin >> revealed;
	
	for(int i = 0; i < revealed; i++){
		int p;
		cin >> p;
		revealedPeople[p] = 1;
	}
	
	
	//������ ������ ��Ƽ�� map �� ǥ�� 
	for(int i = 1; i <= M; i++){
		
		cin >> participated;
		
		for(int k = 0; k < participated; k++){
			int p;
			cin >> p;
			Map[i][p] = 1;
			
		}
	}
	
	//1. ������ �ƴ� ������� ������ ��Ƽ�� ǥ���Ѵ�. 
	for(int i = 1; i <= M; i++){
		
		for(int j = 1; j <= N; j++){
			
			if(Map[i][j] == 1 && revealedPeople[j] == 1){
				revealedParty[i] = 1;
			}
			
		}
		
	}
	
	//2. ������ �ƴ� ����� �Բ� �����ߴ� ������ �𸣴� ����� q�� �ִ´�. 
	for(int i = 1; i <= M; i++){
		for(int j = 1; j<= N; j++){
			if(Map[i][j] == 1 && revealedPeople[j] == 0 && revealedParty[i] == 1){
				q.push(j);
			}
		}
	}
	
	while(!q.empty()){
		
		int idx = q.front();
		q.pop();
		
		//���� ������ �˰Եȴ�. 
		revealedPeople[idx] = 1;
		
		for(int i = 1; i <= M; i++){
			if(Map[i][idx] == 1){
				
				//���� �� ����� ������ ���  ��Ƽ�� revealedParty 
				revealedParty[i] = 1;
				for(int j = 1; j <= N; j++){
					
					//�̻���� ������ ��Ƽ�� ���������� ������ �𸣴� ����� q�� �ִ´�. 
					if(Map[i][j] == 1 && revealedPeople[j] == 0){
						q.push(j);
					}
				}
			}
		}
		
	}
	
	
	
	for(int i = 1; i <= M; i++){
		if(revealedParty[i] == false){
			count++;
		}
	}
	
	cout << count << endl;
	
		
	return 0;
}
