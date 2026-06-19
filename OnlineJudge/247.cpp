#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<utility>
#include<cstring>
#include<map>
#include<stack>

using namespace std;

#define int long long
#define pb push_back

map<string, int> id;
vector<string> name;
vector<vector<int>> adj;

vector<int> disc, low;
vector<bool> inStack;
stack<int> st;

int timer, n, m;

void tarjan(int u){
    disc[u] = low[u] = ++timer;
    st.push(u);
    inStack[u] = 1;

    for(int v: adj[u]){
        if(!disc[v]){
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(inStack[v]){
            low[u] = min(low[u], disc[v]);
        }
    }

    if(low[u] == disc[u]){
        bool first = true;
        while (true) {
            int v = st.top();
            st.pop();
            inStack[v] = false;

            if (!first) cout << ", ";
            cout << name[v];
            first = false;

            if (v == u) break;
        }
        cout << '\n';
    }
}

signed main(){
    int dataset = 1;

    while (cin >> n >> m)
    {
        if(!n && !m) break;

        id.clear();
        name.clear();
        adj.assign(n, vector<int>());
        disc.assign(n, 0);
        low.assign(n, 0);
        inStack.assign(n, false);
        while (!st.empty()) st.pop();
        timer = 0;

        string a, b;
        int idx = 0;

        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            if (!id.count(a)) {
                id[a] = idx++;
                name.push_back(a);
            }
            if (!id.count(b)) {
                id[b] = idx++;
                name.push_back(b);
            }
            adj[id[a]].push_back(id[b]);
        }

        cout << "Calling circles for data set " << dataset++ << ":\n";

        for (int i = 0; i < n; i++) {
            if (disc[i] == 0) {
                tarjan(i);
            }
        }

        cout << '\n';
    }
}