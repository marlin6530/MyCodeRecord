#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back

signed main(){
    int T;
    cin >> T;
    while(T--)
    {
        int g, l;
        cin >> g >> l;
        if(l % g == 0){
            cout << g << " " << l << '\n';
        }
        else{
            cout << -1 << '\n';
        }
    }
}