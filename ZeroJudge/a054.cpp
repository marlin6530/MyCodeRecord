#include<bits/stdc++.h>
using namespace std;

#define int long long

string ans[10] = {
    {"BNZ"},
    {"AMW"},
    {"KLY"},
    {"JVX"},
    {"HU"},
    {"GT"},
    {"FS"},
    {"ER"},
    {"DOQ"},
    {"CIP"}
};

signed main(){
    int n;
    while(cin >> n)
    {
        int sum = n % 10;
        for(int i = 1;i < 9;++i){
            n /= 10;
            sum += n % 10 * i;
        }

        int pos = 10 - sum % 10;
        if(pos == 10) pos = 0;
        cout << ans[pos] << '\n';
    }
}