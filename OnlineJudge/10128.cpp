#include<iostream>

using namespace std;
#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n, l, r;
        cin >> n >> l >> r;
        int dp[15][15][15]{};
        dp[1][1][1] = 1;
        //
        for(int k = 2;k <= n;++k){
            for(int i = 1;i <= n;++i){
                for(int j = 1;j <= n;++j){
                    dp[k][i][j] = dp[k-1][i-1][j] + dp[k-1][i][j-1]
                        + dp[k-1][i][j] * (k-2);
                }
            }
        }
        //
        cout << dp[n][l][r] << '\n';
    }

    return 0;
}