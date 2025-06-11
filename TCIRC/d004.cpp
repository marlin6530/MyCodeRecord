//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

long long n, k, num[55000];
long long ans;
vector<long long> prefix;
vector<long long> weighting;

void solve(long long left, long long right, long long counter){
    if(right - left + 1 < 3 || counter > k){
        return;
    }

    long long cut = 0;
    long long MIN = 1e18;
    for(long long i = left + 1;i < right;++i){
        long long leftHalf = weighting[i - 1] - i * prefix[i - 1];
        long long rightHalf = (weighting[right] - weighting[i]) - i * (prefix[right] - prefix[i]);
        long long cost = leftHalf + rightHalf;
        if(abs(cost) < MIN){
            MIN = abs(cost);
            cut = i;
        }
    }
    ans += num[cut];
    solve(left, cut - 1, counter + 1);
    solve(cut + 1, right, counter + 1);
}

int main(){
    while(cin >> n >> k)
    {
        ans = 0;
        prefix.clear();
        weighting.clear();
        for(int i = 1;i <= n;++i){
            cin >> num[i];
        }

        prefix.push_back(0);
        weighting.push_back(0);
        for(int i = 1;i <= n;++i){
            prefix.push_back(prefix[i - 1] + num[i]);
            weighting.push_back(weighting[i - 1] + num[i] * i);
        }

        solve(1, n, 1);
        cout << ans << '\n';
    }
}