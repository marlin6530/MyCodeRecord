#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n, needs;
    cin >> n >> needs;
    vector<long long> m(n);
    for(long long i=0; i<n; i++){
        cin >> m[i];
    }

    long long low = 0, high = 1e18;
    while(low < high){
        long long mid = (low + high) / 2, product = 0;
        for(auto i : m){
            product += mid / i;
            if(product > needs) break;
        }

        if(product >= needs){
            high = mid;
        }else{
            low = mid + 1;
        }
    }

    cout << low << endl;
}