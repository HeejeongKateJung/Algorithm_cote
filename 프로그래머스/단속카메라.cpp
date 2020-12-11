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
    
    //���� �� ���� ������ ��ǥ
    int cur_exit = routes[0][1];
    
    for(auto next : routes){
        
        // cout << cur_exit << endl;
        //������ �������� ������ �ð����� �ʰ� ���´ٸ� �������� ������� ī�޶� �߰���
        if(cur_exit < next[0]){
            answer++;
            //���� ���� ó������
            cur_exit = next[1];
        }
        
        //������ ���� ������ ���� ������ ī�޶� �߰� ����
        if(cur_exit >= next[1]){
            //���� ���� ������ �ð��� ����� ��ٴ� ���̹Ƿ�
            //���� ���� ������ؼ��� ���� ���� ������ cur_exit �� �Ǿ����.
            cur_exit = next[1];
        }
        
    }
    
    cout << answer << endl;
    return answer;
}
