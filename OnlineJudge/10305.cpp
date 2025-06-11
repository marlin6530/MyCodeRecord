//(C: Completed, P: In Progress, N: Not Started, D: Debugging)
//Status: N

#include<bits/stdc++.h>
//#include<iostream>
using namespace std;

int main(){
    int n, m;
    while (cin >> n >> m)
    {
        if(n == 0 && m == 0) 
            break;

        queue<int> ans;
        vector<int> node;
        node.push_back(0);
        vector<bool> visited(n + 1, false);
        for(int i = 1;i <= n;++i){
            node.push_back(i);
        }
        vector<int> indegree(n + 1);
        vector<vector<int>> graph(n + 1);
        for(int i = 0;i < m;++i){
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            indegree[v]++;
        }

        //dfs
        queue<int> q;
        for(int i = 1;i <= n;++i){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int now = q.front();
            q.pop();
            for(auto i:graph[now]){
                if(--indegree[i] == 0){
                    q.push(i);
                }
            }
            ans.push(now);
        }

        while(!ans.empty()){
            cout << ans.front() << " ";
            ans.pop();
        }
        cout << '\n';
    }
    
}