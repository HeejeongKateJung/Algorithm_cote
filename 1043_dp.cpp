#include <iostream>
#include <queue>
using namespace std;

int N, M;		//사람, 파티 수 
int revealed;	//진실을 아는 사람의 수
int revealedPeople[51];
int Map[51][51];

queue<int> q;


int participated;	//파티에 참가한 사람 수

int count;

				//거짓말을 하는 파티: false
				//진실을말해야 하는 파티: TRUE 
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
	
	
	//참석한 사람들과 파티를 map 에 표시 
	for(int i = 1; i <= M; i++){
		
		cin >> participated;
		
		for(int k = 0; k < participated; k++){
			int p;
			cin >> p;
			Map[i][p] = 1;
			
		}
	}
	
	//1. 진실을 아는 사람들이 참여한 파티를 표시한다. 
	for(int i = 1; i <= M; i++){
		
		for(int j = 1; j <= N; j++){
			
			if(Map[i][j] == 1 && revealedPeople[j] == 1){
				revealedParty[i] = 1;
			}
			
		}
		
	}
	
	//2. 진실을 아는 사람과 함께 참석했던 진실을 모르는 사람을 q에 넣는다. 
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
		
		//이제 진실을 알게된다. 
		revealedPeople[idx] = 1;
		
		for(int i = 1; i <= M; i++){
			if(Map[i][idx] == 1){
				
				//이제 이 사람이 참가한 모든  파티는 revealedParty 
				revealedParty[i] = 1;
				for(int j = 1; j <= N; j++){
					
					//이사람이 참석한 파티에 참석햇지만 진실을 모르는 사람을 q에 넣는다. 
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
