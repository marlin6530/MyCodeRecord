#include<iostream>
#include<vector>
using namespace std;

#define int long long

signed main() {
    int l;
    while(cin >> l && l)
    {
        int n;
        cin >> n;
        vector<int> cuts(n + 2);
        cuts[0] = 0;
        cuts[n + 1] = l;
        for(int i = 1;i <= n;++i){
            cin >> cuts[i];
        }
        int m = n + 2;
        vector<vector<int>> dp(m, vector<int>(m, 0));
        for(int len = 2;len < m;++len){
            for(int i = 0;i + len < m;++i){
                int j = i + len;
                int best = LLONG_MAX;
                for(int k = i + 1;k <= j - 1;++k){
                    int cost = dp[i][k] + dp[k][j] + (cuts[j] - cuts[i]);
                    if(cost < best) best = cost;
                }
                dp[i][j] = best;
            }
        }

        cout << "The minimum cutting is " << dp[0][m - 1] << '\n';
    }

    return 0;
}