#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<utility>
#include<cstring>

using namespace std;

#define int long long
#define pb push_back

vector<int> correct, student;

int lcs(int n){
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= n;++j){
            if(correct[i - 1] == student[j - 1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
              dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][n];
}

signed main(){
    int n;
    if(!(cin >> n)) return 0;

    correct.assign(n, 0);
    int pos;
    for(int i = 1;i <= n;++i){
        cin >> pos;
        correct[pos - 1] = i;
    }

    int val;
    while(cin >> val){
        student.assign(n, 0);
        student[val - 1] = 1;
        for (int i = 2; i <= n; i++) {
            cin >> pos;
            student[pos - 1] = i;
        }
        cout << lcs(n) << '\n';
    }
}