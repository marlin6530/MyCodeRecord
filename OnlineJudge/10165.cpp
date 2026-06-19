#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back

signed main(){
    int n;
    while(cin >> n && n){
        int ans, p;
        cin >> ans;
        for(int i = 1;i < n;++i){
            cin >> p;
            ans ^= p;
        }
        if(!ans) cout << "No\n";
        else cout << "Yes\n";
    }
}