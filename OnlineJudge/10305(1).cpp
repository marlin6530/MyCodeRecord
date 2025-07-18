    //#include<bits/stdc++.h>
    #include<iostream>
    #include<queue>
    #include<vector>
    using namespace std;

    int n, m;
    int indegree[105];
    vector<int> root[105];

    void topo(){
        queue<int> q;
        queue<int> ans;
        for(int i = 1;i <= n;++i){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int now = q.front();
            q.pop();
            ans.push(now);
            for(int i = 0;i < root[now].size();++i){
                int v = root[now][i];
                --indegree[v];
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        
        while(!ans.empty()){
            cout << ans.front();
            ans.pop();
            if(ans.size()) cout << ' ';
        }
        cout << '\n';
    }

    int main(){
        while(cin >> n >> m && (n != 0 || m != 0))
        {
            for(int i = 1;i <= n;++i){
                root[i].clear();
                indegree[i] = 0;
            }
            for(int i = 0;i < m;++i){
                int a, b;
                cin >> a >> b;
                root[a].push_back(b);
                ++indegree[b];
            }
            topo();
        }
    }