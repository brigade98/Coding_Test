/*
마지막 숫자와 이어진 길이를 전체 경우의 수에서 빼면 됨 -> 안 됨
==============================================
역순으로 올라오면서 n 찾고 그 이하의 값들 카운트?  
*/
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int a[300004];
    int n, cnt = 0, n_idx;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        // 가장 마지막 숫자 발견
        if(a[i] == n){
            // 맨 위에 있으면 바로 n - 1 출력
            if(i == 0){
                cout << n - 1;
                return 0;
            }
            n_idx = i;
        }
    }
    // 역순으로 올라가면서 cnt
    int wanted_n = n;
    for(int i = n_idx; i >= 0; --i){
        if(a[i] == wanted_n){
            cnt++;
            wanted_n--;
        }
    }
    //cout << cnt;
    cout << n - cnt;
    return 0;
}