#include <iostream>
#include <vector>

#define MAX 5
using namespace std;

/**
	������ ������ �������� ������ �ֳ� ������ �����̴�.

���տ��� ������ ���� ������, ���ſ� ���������� ��Ҵ� ģ���� �ٽô� �Ĵٵ� ���� ����� ������ ������ �߾���.

������, ������?? ���ſ� ���������� ��Ҵ� ģ���� �ٽ� �ѹ� �Ĵٺ���� �Ѵ�.

���� �� { 1, 2, 3 } = { 2, 1, 3 } �̹Ƿ�, �������� 2�� �Ǵ� ���� �� ���� ����� 1�� �Ĵٵ� ���� ���ƶ� !

���� �� { 1, 2, 3 } != { 2, 1, 3 } �̹Ƿ�, �������� 2�� �Ǵ��� �� ���� ����� 1�� �Ĵٺ��� �Ѵ� !

��� ���̰� �ִ�.
*/


int arr[MAX];
bool visit[MAX];
vector<int> v;
void print(){
	for (int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

void dfs(int cnt) {
	if(cnt == 3){
		print();
		return;
	}
	
	//����: for(int i = IDX; i < MAX; i++)
	//dfs(i, cnt) 
	for(int i = 0; i < MAX; i++){
		if(visit[i])	continue;
		visit[i] = true;
		v.push_back(arr[i]);
		dfs(cnt+1);
		v.pop_back();
		visit[i] = false;
	}
}


int main(void){
	
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5;
	
	dfs(0);
	return 0;
}
