#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<utility>
#include<cstring>
#include<climits>

using namespace std;

#define int long long
#define pb push_back

signed main(){
    int t;
    cin >> t;
    bool first = 1;
    while(t--)
    {
        int target;
        cin >> target;
        int n;
        cin >> n;
        vector<int> dollar(n);
        for(int i = 0;i < n;++i){
            cin >> dollar[i];
        }
        
        vector<int> dp(10050, LLONG_MAX);
        dp[0] = 0;
        for(int j = 1;j < 10050;++j){
            for(int i = 0;i < n;++i){
                if(dollar[i] <= j && dp[j-dollar[i]] != LLONG_MAX){
                    dp[j] = min(dp[j], dp[j-dollar[i]] + 1);
                }
            }
        }
        if(!first) cout << '\n';
        bool hasAns = 0;
        for(int i = target;i <= 10000;++i){
            if(dp[i] != LLONG_MAX){
                cout << i << " " << dp[i];
                hasAns = 1;
                break;
            }
        }
        if(!hasAns){
            cout << 0 << " " << 0;
        }
        first = 0;
    }
}

// 1 1400 3 500 1000 2000