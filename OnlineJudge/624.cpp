#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<utility>
#include<cstring>

using namespace std;

#define ll long long int
#define pb push_back

int main(){
    ll len, n;
    while(cin >> len){
        cin >> n;
        vector<ll> cd(n+1, 0);
        for(int i = 1;i <= n;++i){
            cin >> cd[i];
        }
        //dp
        vector<vector<ll>> dp(n+1, vector<ll>(len+1, 0));
        vector<vector<bool>> choose(n+1, vector<bool>(len+1, 0));
        for(ll i = 1;i <= n;++i){
            for(ll j = 0;j <= len;++j){
                if(j >= cd[i] && dp[i-1][j] < dp[i-1][j - cd[i]] + cd[i]){
                    dp[i][j] = dp[i-1][j - cd[i]] + cd[i];
                    choose[i][j] = 1;
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        vector<ll> result;
        ll j = len;
        for(int i = n;i >= 1;--i){
            if(choose[i][j]){
                result.pb(cd[i]);
                j -= cd[i];
            }
        }

        for(int i = result.size()-1;i >= 0;--i){
            cout << result[i] << " ";
        }
        cout << "sum:" << dp[n][len] << "\n";
    }
}