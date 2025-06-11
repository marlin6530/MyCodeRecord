#include<bits/stdc++.h>
using namespace std;

int graph[50000];
//0: 沒走過, 1: 走過
int vis[50000];
int skip[50005];
int sum = 0;
void dfs(int start){
    if(vis[start] == 0){
        ++sum;
        vis[start] = 1;
        dfs(graph[start]);
    }
    vis[start] = 0;
    skip[start] = 1;
}


int main(){
    int t;
    cin >> t;
    for(int c = 0;c < t;++c){
        int n;
        pair<int, int> ans;
        ans.first = -1;
        cin >> n;
        for(int i = 0;i < n;++i){
            int u, v;
            cin >> u >> v;
            graph[u] = v;

            vis[i + 1] = 0;
            skip[i + 1] = 0;
        }
        for(int i = 1;i <= n;++i){
            sum = 0;
            if(skip[i] == 0){
                dfs(i);
                if(sum > ans.first){
                    ans.first = sum;
                    ans.second = i;
                }
            }
        }
        
        cout << "Case " << c + 1 << ": " << ans.second << '\n'; 
    }
    return 0;
}