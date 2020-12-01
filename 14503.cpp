#include <iostream>

using namespace std;

int n, m, r, c, direction;
int count = 0;

int arr[51][51];


void clean()
{
	if(arr[r][c] == 0){
		arr[r][c] == 2;
		count++;
		cout << "칠함"<<endl;
	}
	
	//방향이 북쪽인경우 
	if(direction == 0){
		if(arr[r][c-1] == 0){
			direction = 3;
			c--;
			clean();
		}
		if(arr[r][c-1] == 2){
			direction = 3;
			clean();
		}
		
		if(arr[r-1][c] != 0 && arr[r][c-1] != 0 && arr[r][c+1] != 0 && arr[r+1][c] == 2){
			r++;
			clean();
		}
		if(arr[r-1][c] != 0 && arr[r][c-1] != 0 && arr[r][c+1] != 0 && arr[r+1][c] == 1){
			cout << count << endl;
		}
	}
	
	//서쪽 
	if(direction == 3){
		if(arr[r+1][c] == 0){
			direction = 2;
			r++;
			clean();
		}
		if(arr[r+1][c] == 2){
			direction = 2;
			clean();
		}
		
		if(arr[r-1][c] != 0 && arr[r+1][c] != 0 && arr[r][c+1] != 0 && arr[r][c+1] == 2){
			c++;
			clean();
		}
		if(arr[r-1][c] != 0 && arr[r+1][c] != 0 && arr[r][c+1] != 0 && arr[r][c+1] == 1){
			cout << count << endl;
		}
	}
	
	//남쪽
	if(direction == 2){
		if(arr[r][c+1] == 0){
			direction = 1;
			c++;
			clean();
		}
		if(arr[r][c+1] == 2){
			direction = 1;
			clean();
		}
		
		if(arr[r][c-1] != 0 && arr[r][c+1] != 0 && arr[r+1][c] != 0 && arr[r-1][c] == 2){
			r--;
			clean();
		}
		if(arr[r][c-1] != 0 && arr[r][c+1] != 0 && arr[r+1][c] != 0 && arr[r-1][c] == 1){
			cout << count << endl;
		}
	}
	
	//동쪽 
	if(direction == 1){
		if(arr[r-1][c] == 0){
			direction = 0;
			r--;
			clean();
		}
		if(arr[r-1][c] == 2){
			direction = 0;
			clean();
		}
		
		if(arr[r-1][c] != 0 && arr[r+1][c] != 0 && arr[r][c+1] != 0 && arr[r][c-1] == 2){
			c--;
			clean();
		}
		if(arr[r-1][c] != 0 && arr[r+1][c] != 0 && arr[r][c+1] != 0 && arr[r][c-1] == 1){
			cout << count << endl;
		}
	}
}


int main(void)
{
	
	cin >> n >> m;
	cin >> r >> c >> direction;
	
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> arr[i][j];
		}
	}
	
	clean();
	
	return 0;
}
