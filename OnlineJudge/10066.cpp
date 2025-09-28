#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int n, m;
    int cnt = 0;
    while(cin >> n >> m && (n || m))
    {
        ++cnt;
        vector<int> a(n), b(m);
        for(int i = 0;i < n;++i){
            cin >> a[i];
        }
        for(int i = 0;i < m;++i){
            cin >> b[i];
        }
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 1;i <=n ;++i){
            for(int j = 1;j <= m;++j){
                if(a[i-1] == b[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        cout << "Twin Towers #" << cnt << '\n';
        cout << "Number of Tiles : " << dp[n][m] << "\n\n";
    }

    return 0;
}