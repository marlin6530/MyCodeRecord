#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n;
    while(cin >> n)
    {
        if((n & 1)) cout << "Odd\n";
        else cout << "Even\n";
    }
}