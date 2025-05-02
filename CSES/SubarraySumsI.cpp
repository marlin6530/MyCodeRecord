//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, x;
    int num[200500];
    cin >> n >> x;
    for(int i = 0;i < n;++i){
        cin >> num[i];
    }
    vector<long long> prefix;
    prefix.push_back(0);
    for(int i = 0;i < n ;++i){
        prefix.push_back(prefix[i] + num[i]);
    }

    int counter = 0;
    for(int i = 0;i <= n;++i){
        long long target = prefix[i] - x;

        auto upper = upper_bound(prefix.begin(), prefix.end(), target);
        auto lower = lower_bound(prefix.begin(), prefix.end(), target);
        counter += upper - lower;
    }
    
    
    cout << counter << '\n';

    return 0;
}