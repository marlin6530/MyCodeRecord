#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define pb push_back

static int dp[300][1125][20];

int main(){
    int n, k;
    vector<int> prime;
    vector<bool> is_prime(1125, 1);
    prime.pb(0);
    prime.pb(2);
    for(int i = 3;i <= 1120;i += 2){
        if(is_prime[i]){
            prime.pb(i);
            for(int j = i * i;j <= 1120;j += i){
                is_prime[j] = 0;
            }
        }
    }
    //dp
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    int s = prime.size();
    for(int i = 1;i < s;++i){
        for(int j = 0;j <= 1120;++j){
            for(int k = 0;k <= 14;++k){
                if(j >= prime[i] && k >= 1)
                    dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-prime[i]][k-1];
                else
                    dp[i][j][k] = dp[i-1][j][k];
            }
        }
    }
    while(cin>>n>>k && (n || k))
    {
        cout << dp[s-1][n][k] << "\n";
    }
}