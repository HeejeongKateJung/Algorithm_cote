//#include <iostream>
//using namespace std;
//
//int n, arr[501][501];
//int dp[501][501];
//
////동서남북 순 
//int dirI[4] = {0, 0, 1, -1};
//int dirJ[4] = {1, -1, 0, 0}; 
//
//int Max(int x, int y){
//	return x > y ? x : y;
//}
//
//int main(void)
//{
//	cin >> n;
//	
//	
//	for(int i = 0; i < n; i++){
//		for(int j = 0; j < n; j++){
//			cin >> arr[i][j];
//			dp[i][j] = 1;
//		}
//	}
//	
//	
//	for(int i = 0; i < n; i++){
//		for(int j = 0; j < n; j++){
//			
//			for(int k = 0; k < 4; k++){
//				
//				int ni = i+dirI[k];
//				int nj = j+dirJ[k];
//				
//				//상하좌우에 나보다 큰 애들이 있다면,
//				//그 쪽으로 갈 수 없다. 
//				if(ni < 0 || ni >= n || nj < 0 || nj >= n){
//					continue;
//				}
//				
//				
//				if(arr[ni][nj] <= arr[i][j]){
//					continue;
//					
//				}
//				
//				dp[i][j] = Max(dp[i][j], dp[ni][nj] + 1);
//				
//			}
//			
////			cout << endl;
////		for(int i = 0; i < n; i++){
////			for(int j = 0; j < n; j++){
////				cout << dp[i][j] << " ";
////			}
////			cout << endl;
////			
//		}
//		
//	}
//	
//	int ans = 0;
//	for(int i = 0; i < n; i++){
//		for(int j = 0; j < n; j++){
////			cout << dp[i][j] << " ";
//			ans = Max(ans, dp[i][j]);
//		}
////		cout << endl;
//	}
//	
//	cout << ans;
//	return 0;
//}
#include <iostream>
using namespace std;
 
int dp[500][500]={0};
int map[500][500]={0};
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int n;
 
int len=0;
int dfs(int y,int x){
    
    if(dp[y][x])
        return dp[y][x];
    
    dp[y][x]=1;
    
    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        
        if(ny<0 ||ny>=n || nx<0 || nx>=n)
            continue;
        
        if(map[y][x]>=map[ny][nx])
            continue;
        
        dp[y][x]=max(dp[y][x],dfs(ny,nx)+1);
        
    }
    
    return dp[y][x];
}
int main(){
    
    cin>>n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&map[i][j]);
        }
    }
    
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans=max(ans,dfs(i,j));
        }
    }
    cout<<ans<<endl;
    return 0;
}
