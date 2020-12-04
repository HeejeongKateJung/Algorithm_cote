#include <iostream>
#include <vector>
using namespace std;


int n;
int height[50];
int weight[50];
int level[50];


int main(void)
{
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		cin >> weight[i] >> height[i];
	}
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++){
			if(i == j){
				continue;
			}
			
			if(weight[i] < weight[j] && height[i] < height[j]){
				level[i]++;	
			}
		}
	}
	
	for(int i = 0; i < n; i++)
	{
		cout << level[i]+1 << " ";
	}
	
	
	return 0;
}
