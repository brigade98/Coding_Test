/*
회전 i j
널문자 어케
*/
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int max_length = 0;
    vector<string> s(5);
    for(int i = 0; i < 5; i++){
        cin >> s[i];
        if(s[i].length() > max_length) max_length = s[i].length();
    }
    for(int i = 0; i < max_length; i++){
        for(int j = 0; j < 5; j++){
            if(s[j][i] != '\0'){
                cout << s[j][i];
            }
        }
    }

}