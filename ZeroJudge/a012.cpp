#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n, m;
    while(cin >> n >> m)
    {
        if(n < m)
            cout << m - n << '\n';
        else
            cout << n - m << '\n';
    }
    
}