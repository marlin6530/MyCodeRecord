#include<bits/stdc++.h>
using namespace std;

long long fastPow(long long base, long long exponent){
    long long  result = 1, mod = 1e9+7;
    while(exponent > 0){
        if(exponent & 1){
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent >>= 1;
    }

    return result;
}

int main(){
    long long n, base, exponent;
    cin >> n;
    while(n--){
        cin >> base >> exponent;
        cout << fastPow(base, exponent) << endl;
    }
    
    return 0;
}