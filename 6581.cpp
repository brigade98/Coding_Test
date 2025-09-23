/*
여러 개의 연속된 개행 문자, 공백 문자, 탭 문자는 하나의 공백문자로 출력
*/
#include<iostream>
#include<vector>
using namespace std;

int main(){
    string word;
    int cnt = 0;
    int flag = 0;
    while(cin >> word){
        // 새 줄
        if(word == "<br>"){
            cout << '\n';
            cnt = 0;
        }
        // 새 줄 + '-' 80개
        else if(word == "<hr>"){
            if(cnt > 0) cout << '\n';
            for(int i = 0; i < 80; i++){
                cout << '-';
            }
            cout << '\n';
            cnt = 0;
        }
        // 일반 단어
        else{
            // 새 줄에서 시작
            if(cnt == 0){
                cnt = word.length();
                cout << word;
            }
            // 헌 줄에서 시작
            else{
                if(cnt + word.length() + 1 >= 80){
                    cout << '\n' << word;
                    cnt = word.length();
                }
                else{
                    cout << " " << word;
                    cnt += word.length() + 1;
                }
            }
        }
    }
}