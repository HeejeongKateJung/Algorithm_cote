#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dy[3] = {1, 0, -1};
int dx[3] = {0, 1, -1};
int v[1001][1001];

void print(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

vector<int> solution(int n) {
    vector<int> answer;
    
    int k = 0, num = 2;
    int y = 0, x = 0;
    v[0][0] = 1;
    
    int curDir = 0;
    
    while(true){
        bool isThereEmpty = false;
        for(int k = curDir; k < curDir+3; k++){
            int ny = y+dy[k%3];
            int nx = x+dx[k%3];
            
            if(ny >= n || nx >= n || ny < 0 || nx < 0)  continue;
            if(v[ny][nx] != 0)  continue;
            
            v[ny][nx] = num;
            num++;
            curDir = k;
            isThereEmpty = true;
            y = ny;
            x = nx;
            break;
        }
        if(!isThereEmpty)   break;
    }
    
    print();
    
    return answer;
}

int main(void){
	int n;
	cin >> n;
	solution(n);
	return 0;
} 
