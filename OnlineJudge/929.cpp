#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<utility>
#include<cstring>
#include<queue>
#include<climits>

using namespace std;

#define int long long
#define pb push_back
#define pii pair<int, int>
#define F first
#define S second

const int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

signed main(){
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> graph(n+2, vector<int>(m+2, 0));
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= m;++j){
                cin >> graph[i][j];
            }
        }
        //{d, {x, y} }
        priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
        vector<vector<int>> d(n+2, vector<int>(m+2, LLONG_MAX));
        d[1][1] = graph[1][1];
        pq.push({d[1][1], {1, 1}});
        while(!pq.empty()){
            int x = pq.top().S.F;
            int y = pq.top().S.S;
            pq.pop();
            for(int i = 0;i < 4;++i){
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if(nx >= 1 && ny >= 1 && nx <= n && ny <= m){
                    if(d[nx][ny] > d[x][y] + graph[nx][ny]){
                        d[nx][ny] = d[x][y] + graph[nx][ny];
                        pq.push({d[nx][ny], {nx, ny}});
                    }
                }
            }
        }

        // for(int i = 1;i <= n;++i){
        //     for(int j = 1;j <= m;++j){
        //         cout << d[i][j] << " ";
        //     }
        //     cout << '\n';
        // }
        cout << d[n][m] << '\n';
    }
}
/*
2
4
5
0 3 1 2 9
7 3 4 9 9
1 7 5 5 3
2 3 4 2 5
1
6
0 1 2 3 4 5
[WA]
queue<pii> q;
q.push({1, 1});
vector<vector<int>> d(n+2, vector<int>(m+2, LLONG_MAX));
vector<vector<bool>> inQ(n+2, vector<bool>(m+2, 0));
d[1][1] = graph[1][1];
inQ[1][1] = 1;
while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    inQ[x][y] = 0;
    for(int i = 0;i < 4;++i){
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if(nx == 0 || ny == 0 || nx == n+1 || ny == m+1) continue;
        if(d[nx][ny] > d[x][y] + graph[nx][ny]){
            d[nx][ny] = d[x][y] + graph[nx][ny];
            if(!inQ[nx][ny]){
                q.push({nx, ny});
                inQ[nx][ny] = 1;
            }
        }
    }
}
*/