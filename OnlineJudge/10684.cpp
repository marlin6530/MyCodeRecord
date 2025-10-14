#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long

int dp(vector<int> p){
    int dp = 0;
    int m = -1;
    int n = p.size();
    for(int i = 0;i < n;++i){
        dp = max(p[i], dp + p[i]);
        m = max(m, dp);
    }

    return m;
}

int maxSubarray(vector<int> p){
    int n = p.size(), better = -1, sum = 0;
    for(int i = 0;i < n;++i){
        sum += p[i];
        if(sum < 0){
            sum = 0;
        }else{
            better = max(better, sum);
        }
    }

    return better;
}

signed main(){
    int n;
    while(cin >> n && n){
        vector<int> p(n);
        for(int i = 0;i < n;++i){
            cin >> p[i];
        }

        //int ans = dp(p);
        int ans = maxSubarray(p);

        if (ans > 0)
            cout << "The maximum winning streak is " << ans << ".\n";
        else
            cout << "Losing streak.\n";
    }

    return 0;
}