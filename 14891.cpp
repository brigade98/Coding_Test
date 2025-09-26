/*
바로 회전 X
돌 돌 돌 안 안
int decision[5];
1: 시계
0: X
-1: 반시계
idx에 삽입


*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


vector<deque<int>> tobni(5);
void rotating(int idx, int dir){
    if(dir == 1){
        tobni[idx].push_front(tobni[idx].back());
        tobni[idx].pop_back();
    }
    else if(dir == -1){
        tobni[idx].push_back(tobni[idx].front());
        tobni[idx].pop_front();
    }
    else return;
}


int main(){
    int res = 0;
    int rotating_cnt;
    
    for(int i = 1; i <= 4; i++){
        string s;
        cin >> s;
        for(char c : s){
            tobni[i].push_back(c - '0');
        }
    }
    // 돌리는 명령 저장
    vector<pair<int, int>> a;   
    scanf("%d", &rotating_cnt);
    for(int i = 0; i < rotating_cnt; i++){
        int idx, dir;
        scanf("%d %d", &idx, &dir);
        a.push_back({idx, dir});
    }

    // 돌리는 톱니 기준 분할
    for(auto _a : a){
        vector<int> decision(5, 0);
        decision[_a.first] = _a.second;
        for(int i = _a.first; i > 1; i--){
            // 회전 O
            if(tobni[i][6] != tobni[i - 1][2]){
                decision[i - 1] = -(decision[i]);
            }
            // 회전 X -> 그 옆에도 안 돌음?
            else break;
        }
        for(int i = _a.first; i < 4; i++){
            if(tobni[i][2] != tobni[i + 1][6]){
                decision[i + 1] = -(decision[i]);
            }
            else break;
        }
        // 실제로 돌림
        for(int i = 1; i <= 4; i++){
            rotating(i, decision[i]);
        }
    }
    if(tobni[1][0] == 1) res += 1;
    if(tobni[2][0] == 1) res += 2;
    if(tobni[3][0] == 1) res += 4;
    if(tobni[4][0] == 1) res += 8;

    cout << res;
}