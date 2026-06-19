#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<utility>
#include<cstring>

using namespace std;

#define int long long
#define pb push_back

int n;
int MAX = -1;
int fartherest;
vector<vector<int>> node;

void dfs(int n, int p, int d){
    if(d > MAX){
        MAX = d;
        fartherest = n;
    }
    for(auto i: node[n]){
        if(i == p) continue;
        dfs(i, n, d+1);
    }
}

signed main(){
    cin >> n;
    node = vector<vector<int>> (n + 1, vector<int>(0, 0));
    for(int i = 0;i < n - 1;++i){
        int u, v;
        cin >> u >> v;
        node[u].pb(v);
        node[v].pb(u);
    }
    dfs(1, 1, 0);
    MAX = -1;
    dfs(fartherest, fartherest, 0);

    cout << MAX;

    return 0;
}