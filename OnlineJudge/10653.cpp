//(C: Completed, P: In Progress, N: Not Started, D: Debugging)
//Status: N

#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int r, c;
    while(cin >> r >> c)
    {
        if(r == 0 && c == 0) break;
        
        vector<vector<int>> map(r, vector<int>(c, 0));
        int n;
        cin >> n;
        for(int i = 0;i < n;++i){
            int x, y, m;
            cin >> x >> m;
            for(int j = 0;j< m;++j){
                cin >> y;
                map[x][y] = -1;
            }
        }
        int x[2], y[2];
        cin >> x[0] >> y[0] >> x[1] >> y[1];
        //bfs
        queue<pair<int, int>> q;
        q.push({x[0], y[0]});
        map[x[0]][y[0]] = 1;
        while(!q.empty()){
            auto p = q.front();
            q.pop();

            int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
            for(int i = 0;i < 4;++i){
                int nx = p.first + dir[i][0];
                int ny = p.second + dir[i][1];

                if(nx >= 0 && nx < r && ny >= 0 && ny < c && map[nx][ny] == 0){
                    map[nx][ny] = map[p.first][p.second] + 1;
                    if(nx == x[1] && ny == y[1]){
                        cout << map[nx][ny] - 1 << '\n';
                        q = queue<pair<int, int>>();
                        break;
                    }
                    q.push({nx, ny});
                }
            }
        }
    }
    
    
}