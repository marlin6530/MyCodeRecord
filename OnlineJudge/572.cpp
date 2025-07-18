//Time Complexity: O()

//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int m, n;
char map[150][150];
bool visited[150][150];
int ans;
int dir[8][2] = {{-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}};

void dfs(int x, int y){
    visited[x][y] = 1;
    for(int i = 0;i < 8;++i){
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if(nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && map[nx][ny] == '@'){
            dfs(nx, ny);
        }
    }
}

int main(){
    while(cin >> m >> n && m != 0)
    {
        ans = 0;
        for(int i = 0;i < m;++i){
            for(int j = 0;j < n;++j){
                cin >> map[i][j];
                visited[i][j] = 0;
            }
        }
        
        for(int i = 0;i < m;++i){
            for(int j = 0;j < n;++j){
                if(!visited[i][j] && map[i][j] == '@'){
                    dfs(i, j);
                    ++ans;
                }
            }
        }

        cout << ans << '\n';
    }



    return 0;
}