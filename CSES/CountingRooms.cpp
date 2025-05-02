//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n, m;
    char map[1500][1500];
    bool used[1500][1500];
    cin >> n >> m;
    for(int i = 0;i < n;++i){
        for(int j = 0;j < m;++j){
            cin >> map[i][j];
        }
    }

    const int dir[2][4] = {
        //up down left right
        {0, 0, -1, 1},
        {-1, 1, 0, 0}
    };
    
    int counter = 0;
    for(int i = 0;i < n;++i){
        for(int j = 0;j < m;++j){
            if(map[i][j] == '.' && !used[i][j]){
                counter++;
                queue< pair<int, int> > q;
                q.push({i, j});
                used[i][j] = true;
                
                while(!q.empty()){
                    int x = q.front().first, y = q.front().second;
                    q.pop();
                    for(int d = 0;d < 4;++d){
                        int nx = x + dir[0][d], ny = y + dir[1][d];
                        if(nx >= 0 && nx < n && ny >= 0 && ny < m && 
                            map[nx][ny] == '.'&& !used[nx][ny]){
                            q.push({nx, ny});
                            used[nx][ny] = true;
                        }
                    }
                }
            }
        }
    }

    cout << counter << '\n';

    return 0;
}