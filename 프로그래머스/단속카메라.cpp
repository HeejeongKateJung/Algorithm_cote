#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(vector<int> a, vector<int> b){
    return a[0] < b[0] ? true : false;
}

int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    sort(routes.begin(), routes.end());
    
    //현재 내 차가 나가는 좌표
    int cur_exit = routes[0][1];
    
    for(auto next : routes){
        
        // cout << cur_exit << endl;
        //뒤차가 현재차가 나가는 시간보다 늦게 들어온다면 현재차를 잡기위해 카메라를 추가함
        if(cur_exit < next[0]){
            answer++;
            //현재 차는 처리했음
            cur_exit = next[1];
        }
        
        //뒤차가 현재 차보다 빨리 나가면 카메라 추가 안함
        if(cur_exit >= next[1]){
            //현재 차가 나가는 시간이 충분히 길다는 뜻이므로
            //다음 차를 잡기위해서는 먼저 나갈 차량이 cur_exit 이 되어야함.
            cur_exit = next[1];
        }
        
    }
    
    cout << answer << endl;
    return answer;
}
