/*
수열 S의 (가장 작은 원소+1) or (1)부터 체크
---------------------------------
정렬 후 각 원소 접근?
---------------------------------
0은 자연수가 아니다. -> 1부터 시작
=================================
4
2 1 2 7
sort -> 1 2 2 7
-----------------
#1
target: 1, num: 1
#2
target: 2, num: 2
#3
target: 3, num: 2  -> error
=> +1로 하면 안 됨
-----------------
#1
target: 1, num: 1
#2
target: 2, num: 2
#3
target: 4, num: 2
#4
target: 6, num: 7 -> find == 7 (target: 3, 5는 부분 수열의 합으로 만족)
=> 구간 합?
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    int n, find = 1;
    vector<int> num;
    cin >> n;
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        num.push_back(temp);
    }
    sort(num.begin(), num.end());
    for(int _num : num){
        if(_num > find){
            cout << find;
            return 0;
        }
        // 업데이트
        else find += _num;
    }
    // 반복문 동안 못 찾으면
    cout << find;
}