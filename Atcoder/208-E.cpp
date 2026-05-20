#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<utility>
#include<cstring>
#include<set>
#include<queue>

using namespace std;

#define int long long
#define pb push_back

int n, k;
vector<int> prods;
string s;
// dp[pos][prod_pos][is_limit][is_start]
int dp[20][10000][2][2];

int get_id(int p){
    return lower_bound(prods.begin(), prods.end(), p) - prods.begin();
}

int dfs(int pos, int idx, bool limit, bool start){
    if(pos == (int)s.size())
        return (start && prods[idx] <= k) ? 1 : 0; 
    
    if(dp[pos][idx][limit][start] != -1)
        return dp[pos][idx][limit][start];

    int res = 0;
    int ceiling = limit ? s[pos] - '0' : 9;

    for(int i = 0;i <= ceiling;++i){
        bool next_limit = (limit && i == ceiling);
        bool next_start = (start || i != 0);

        if(!next_start){
            res += dfs(pos + 1, idx, next_limit, false);
        }
        else{
            int product = prods[idx] * i;
            if(product > k) product = k + 1;
            res += dfs(pos + 1, get_id(product), next_limit, true);
        }
    }

    dp[pos][idx][limit][start] = res;
    return res;
}

signed main(){
    while(cin >> n >> k)
    {
        s = to_string(n);
        prods.clear();

        //預處理
        set<int> st;
        st.insert(0);
        queue<int> q;
        q.push(1);
        st.insert(1);
        while(!q.empty()){
            int num = q.front();
            q.pop();
            for(int i = 2;i <= 9;++i){
                if(num <= k / i){
                    int next = num * i;
                    if(st.find(next) == st.end()){
                        st.insert(num * i);
                        q.push(num * i);
                    }
                }
            }
        }
        st.insert(k + 1);
        for(int i: st) prods.pb(i);
        sort(prods.begin(), prods.end());

        //初始化
        memset(dp, -1, sizeof(dp));

        cout << dfs(0, 1, true, false) << endl;
    }
}