#include<iostream>
#include<string>
#include<vector>
using namespace std;

#define int long long

signed main(){
    while(1)
    {
        vector<string> s1, s2;
        string s;
        if(!(cin >> s)) break;
        if(s != "#"){
            s1.push_back(s);
            while(cin >> s)
            {
                if(s == "#") break;
                s1.push_back(s);
            }
        }
        
        while(cin >> s)
        {
            if(s == "#") break;
            s2.push_back(s);
        }
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        vector<vector<int>> prev(n+1, vector<int>(m+1, 0));
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= m;++j){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    prev[i][j] = 0;
                }else{
                    if(dp[i-1][j] < dp[i][j-1]){
                        dp[i][j] = dp[i][j-1];
                        prev[i][j] = 2;
                    }else{
                        dp[i][j] = dp[i-1][j];
                        prev[i][j] = 1;
                    }
                }
            }
        }
        vector<string> ans;
        int i = n, j = m;
        while(i > 0 && j > 0)
        {
            if(prev[i][j] == 0){
                ans.push_back(s1[i-1]);
                --i;
                --j;
            }
            else if(prev[i][j] == 1){
                --i;
            }
            else{
                --j;
            }
        }

        for(int i = ans.size() - 1;i >=0;--i){
            cout << ans[i];
            if(i != 0) cout << " ";
        }
        cout << '\n';
        }
    return 0;
}