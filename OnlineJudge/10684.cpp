#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long

signed main(){
    int n;
    while(cin >> n && n){
        vector<int> p(n);
        for(int i = 0;i < n;++i){
            cin >> p[i];
        }

        int dp = 0;
        int m = -1;
        for(int i = 0;i < n;++i){
            dp = max(p[i], dp + p[i]);
            m = max(m, dp);
        }

        if (m > 0)
            cout << "The maximum winning streak is " << m << ".\n";
        else
            cout << "Losing streak.\n";
    }

    return 0;
}