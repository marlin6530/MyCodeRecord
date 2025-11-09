#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include <cstring>
#include <queue>
#include <climits>

using namespace std;

#define int long long
#define pb push_back

signed main()
{
    int N, m, n, s, t;
    cin >> N;
    for (int cnt = 1; cnt <= N; ++cnt)
    {
        cin >> n >> m >> s >> t;
        vector<vector<int>> w(n, vector<int>(n, -1));
        vector<vector<int>> neighbor(n);
        for (int i = 0; i < m; ++i)
        {
            int u, v, x;
            cin >> u >> v >> x;
            w[u][v] = x;
            w[v][u] = x;
            neighbor[u].push_back(v);
            neighbor[v].push_back(u);
        }
        //
        vector<int> d(n, LLONG_MAX);
        d[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : neighbor[u])
            {
                if (d[v] > d[u] + w[u][v])
                {
                    d[v] = d[u] + w[u][v];
                    q.push(v);
                }
            }
        }
        if (d[t] == LLONG_MAX)
            cout << "Case #" << cnt << ": unreachable\n";
        else
            cout << "Case #" << cnt << ": " << d[t] << '\n';
    }
}