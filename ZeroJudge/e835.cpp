#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n;
    while(cin >> n)
    {
        int a, b = 1, c;
        if(n <= 2500){
            a = 1;
            while(n > 25){
                ++b;
                n -= 25;
            }
            c = n;
        }
        else if(n > 7500){
            a = 3;
            n -= 7500;
            while(n > 25){
                ++b;
                n -= 25;
            }
            c = n;
        }
        else{
            a = 2;
            n -= 2500;
            while(n > 50){
                ++b;
                n -= 50;
            }
            c = n;
        }

        cout << a << " " << b << " " << c << '\n';
    }
}