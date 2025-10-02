#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int h, m;
    while(cin >> h >> m)
    {
        if(h >= 8 && h < 17){
            cout << "At School\n";
        }
        else if(h == 7 && m >= 30){
            cout << "At School\n";
        }
        else cout << "Off School\n";
    }
}