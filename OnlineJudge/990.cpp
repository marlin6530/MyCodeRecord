#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<utility>
#include<cstring>

using namespace std;

#define int long long
#define pb push_back

signed main(){
    int n, w, k;
    bool first = 1;
    while(cin >> k >> w)
    {
        cin >> n;
        vector<int> d(n+1, 0), v(n+1, 0), t(n+1, 0);
        for(int i = 1;i <= n;++i){
            cin >> d[i] >> v[i];
            t[i] = 3 * w * d[i];
        }
        //dp
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        vector<vector<bool>> ch(n+1, vector<bool>(k+1, 0));
        for(int i = 1;i <= n;++i){
            for(int j = 0;j <= k;++j){
                dp[i][j] = dp[i-1][j];
                if(j >= t[i] && dp[i][j] < dp[i-1][j-t[i]] + v[i]){
                    dp[i][j] = dp[i-1][j-t[i]] + v[i];
                    ch[i][j] = 1;
                }
            }
        }
        //path
        vector<int> path;
        int j = k;
        for(int i = n;i >= 1;--i){
            if(ch[i][j]){
                path.pb(i);
                j -= t[i];
                if(j <= 0) break;
            }
        }
        if(!first) cout << '\n';
        first = 0;
        cout << dp[n][k] << "\n" << path.size() << "\n";
        reverse(path.begin(), path.end());
        for (int idx : path) {
            cout << d[idx] << " " << v[idx] << "\n";
        }
        string blank;
        cin.ignore();
        getline(cin, blank);
    }
}