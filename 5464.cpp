/*
시뮬레이션?, queue
==============================
flag로 빈 자리 없는지 체크

차가 빠지고 나서, q에 있는 차량을 넣어야 함
다시 is_parking 순회하면서 low idx 찾아야 할지
or 아니면 방금 나간 자리에 할당? -> ㅁㄹ

*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n, m, res = 0;
    cin >> n >> m;

    queue<int> q;
    vector<int> is_parking(n, 0);
    vector<int> area_price(n), vehicle_weight(m);

    for(int i = 0; i < n; i++){
        cin >> area_price[i];
    }
    for(int i = 0; i < m; i++){
        cin >> vehicle_weight[i];
    }
    // 시뮬레이션
    for(int i = 0; i < 2 * m; i++){
        int v_num;
        cin >> v_num;
        // 진입
        if(v_num > 0){
            // 자리 남았는지
            int possible = -1;
            for(int idx = 0; idx < n; idx++){
                if(is_parking[idx] == 0){
                    possible = idx;
                    break;
                }
            }
            // 주차 공간 있으면
            if(possible != -1){
                is_parking[possible] = v_num;
                res += area_price[possible] * vehicle_weight[v_num - 1];
            }
            // 없으면 q에 삽입
            else q.push(v_num);
        }
        // 퇴장
        else{
            v_num = abs(v_num);
            int possible;
            for(int idx = 0; idx < n; idx++){
                if(is_parking[idx] == v_num){
                    is_parking[idx] = 0;
                    possible = idx;
                    break;
                }
            }
            // 차 빠지고 자리 체크
            if(!q.empty()){
                int vv_num = q.front(); q.pop();
                is_parking[possible] = vv_num;
                res += area_price[possible] * vehicle_weight[vv_num - 1];
            }
        }
    }
    cout << res;
}