/*
안전 거리: 해당 칸과 아기 상어와의 최소 거리 -> BFS

dist 배열에 안전 거리 저장하고 돌면서 찾기
-----------------------------------
12시부터 시계 방향으로 8방향
1 1 0 -1 -1 -1 0
0 1 1 -1 0 -1 -1
-----------------------------------
*/
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int mp[54][54]; int dist[54][54];
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
queue<pair<int, int>> q;
int n, m;

void BFS(){
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for(int i = 0; i < 8; i++){
            int ny = y + dy[i]; int nx = x + dx[i];
            // 범위 & 방문 처리
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(dist[ny][nx]) continue;
            dist[ny][nx] = dist[y][x] + 1;
            q.push({ny, nx});
        }

    }
}
int main(){
    int res = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mp[i][j];
            if(mp[i][j] == 1){
                q.push({i, j});
                // 미방문 처리 + 1
                dist[i][j] = 1;
            }
        }
    }
    BFS();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(dist[i][j] > res) res = dist[i][j];
        }
    }
    // +1 한거 빼줘야 함
    cout << res - 1;
}