#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<utility>
#include<cstring>
#include<iomanip>

using namespace std;

#define int long long
#define pb push_back

void bg(int n){
    if(n >= 10000000){
        cout << " " << n / 10000000 << " kuti";
        n %= 10000000;
    }
    if(n >= 100000){
        cout << " " << n / 100000 << " lakh";
        n %= 100000;
    }
    if(n >= 1000){
        cout << " " << n / 1000 << " hajar";
        n %= 1000;
    }
    if(n >= 100){
        cout << " " << n / 100 << " shata";
        n %= 100;
    }
    if(n > 0){
        cout << " " << n;
    }
}

signed main(){
    int n;
    int t = 0;
    while(cin >> n)
    {
        cout << setw(4) << setfill(' ') << ++t << ".";
        if(n == 0){
            cout << " " << 0;
            continue;;
        }
        if(n > 10000000){
            bg(n / 10000000);
            cout << " kuti";
            bg(n % 10000000);
        }
        else{
            bg(n);
        }
        cout << '\n';
    }
}