/*
O(N) -> 6 * 10,000 * 6 -> ~360,000
-------------------
A: 윗면
B, C, D, E: 옆면
F: 아랫면
-------------------
1. [1번 주사위] 윗면 - 아랫면 결정
2. 옆면 최대값 계산
3. 나머지 주사위들 차례로 결정
반복
====================
1번 주사위부터 결정(6번) -> 자동으로 2번... -> 완탐?
*/
#include<iostream>
#include<vector>
using namespace std;

int calc_max_side_value(const vector<int>& dice, int top, int bot){
    int max_value = 0;
    for(int i = 0; i < 6; i++){
        if(dice[i] == top || dice[i] == bot) continue;
            max_value = max(max_value, dice[i]);
    }
    return max_value;
}
int calc_opp_idx(int idx){
    switch(idx){
        case 0: return 5;
        case 1: return 3;
        case 2: return 4;
        case 3: return 1;
        case 4: return 2;
        case 5: return 0;
    }
}

int main(){
    int n, res = 0;    
    cin >> n;
    vector<int> Dice[n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 6; j++){
            int temp; 
            cin >> temp;
            Dice[i].push_back(temp);
        }
    }
    // 1번 주사위 루프
    for(int i = 0; i < 6; i++){
        int _res = 0;
        int top = Dice[0][i];
        int bot = Dice[0][calc_opp_idx(i)];
        int max_value = calc_max_side_value(Dice[0], top, bot);
        _res += max_value;

        // 결정된 1번 주사위 기반으로 다른 주사위들 결정
        for(int j = 1; j < n; j++){
            // top 갱신해야 함
            // bot == n-1번 주사위 top
            bot = top;
            int bot_idx;

            // 현재 주사위의 모양 결정
            for(int k = 0; k < 6; k++){
                if(Dice[j][k] == bot){
                    bot_idx = k;
                    break;
                }
            }
            // n+1 주사위를 위한 top
            top = Dice[j][calc_opp_idx(bot_idx)];
            // n번 주사위 까지의 최대 옆면 값
            _res += calc_max_side_value(Dice[j], top, bot);
        }
        res = max(res, _res);
    }
    cout << res;
}