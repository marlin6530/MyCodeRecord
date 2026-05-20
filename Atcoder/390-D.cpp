#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<utility>
#include<cstring>
#include<unordered_set>

using namespace std;

#define int long long
#define pb push_back

unordered_set<int> result;
int group[15];
int n;
int a[15];

void dfs(int idx, int cnt, int cur){
    if(idx == n){
        result.insert(cur);
        return;
    }

    for(int i = 0;i < cnt;++i){
        int old = group[i];
        int next = cur ^ old ^ (old + a[idx]);

        group[i] += a[idx];
        dfs(idx + 1, cnt, next);
        group[i] = old;
    }

    group[cnt] = a[idx];
    dfs(idx + 1, cnt + 1, cur ^ a[idx]);
    group[cnt] = 0;

    return;
}

signed main(){
    while(cin >> n)
    {
        result.clear();
        for(int i = 0;i < n;++i){
            cin >> a[i];
        }

        dfs(0, 0, 0);

        cout << result.size() << '\n';
    }
    
}