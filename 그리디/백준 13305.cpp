#include <iostream>
#include <vector>

using namespace std;

long long solution(int N, vector<long long> distance, vector<long long> price)
{
	
	long long min_price = price[0];
	long long ans = 0;
	long long remaining = distance[0];
	for(int i = 1; i < N; i++){
		
//		cout << "min_price: " << min_price << endl;
//		cout << "price[i]: " << price[i] << endl;
		
		//현재 있는 도시가 다음 도시보다 비싸므로 다음도시까지 갈 만큼만
		//구매한다. 
		if(min_price > price[i]){
			ans+=min_price*remaining;
			remaining = distance[i];
			min_price = price[i];
			
			
		}
		//다음 도시가 더 비싸므로 더 싼 도시가 나올 때까지 존버한다. 
		else{
			
			remaining+=distance[i];
		}
		
		if(i == N-1){
			ans+=min_price*remaining;
		}
		
//		cout << "ans: " << ans << endl;
		
	}
	
	return ans;
	
}

int main(void)
{
	int N;
	vector<long long> distance;
	vector<long long> price;
	
	cin >> N;
	
	for(int i = 0; i < N-1; i++){
		int a;
		cin >> a;
		distance.push_back(a);
	}
	
	distance.push_back(0);
	
	for(int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		price.push_back(a);
	}
	
	long long ans = solution(N, distance, price);
	cout << ans << endl;
	return 0;
}
