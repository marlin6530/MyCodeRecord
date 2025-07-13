#include<bits/stdc++.h>
// #include<iostream>
// #include<vector>
// #include<cmath>
using namespace std;

int n, k, num[55000];
long long ans;
vector<long long> prefix;
vector<long long> weighting;

void solve(int left, int right, int depth){
    if(right - left + 1 < 3 || depth == k){
        return;
    }

    int cut = 0;
    long long MIN = LLONG_MAX;
    for(int i = left + 1;i < right;++i){
        /*
        // {left...i-1}
        long long leftWeight = weighting[i - 1] - weighting[left - 1];
        long long leftSum = prefix[i - 1] - prefix[left - 1];
        long long leftHalf = leftWeight - i * leftSum;
        // {i+1...right}
        long long rightWeight = weighting[right] - weighting[i];
        long long rightSum = prefix[right] - prefix[i];
        long long rightHalf = rightWeight - i * rightSum;
        long long cost = leftHalf + rightHalf;
        */
        long long totalWeight = weighting[right] - weighting[left - 1];
        long long totalPrefix = prefix[right] - prefix[left - 1];
        long long cost = totalWeight - (long long)i * totalPrefix;

        long long tmp = llabs(cost);
        if(tmp < MIN){
            MIN = tmp;
            cut = i;
        }
    }
    
    ans += num[cut];
    solve(left, cut - 1, depth + 1);
    solve(cut + 1, right, depth + 1);
}

int main(){
    while(cin >> n >> k)
    {
        ans = 0;
        for(int i = 1;i <= n;++i){
            cin >> num[i];
        }

        prefix.assign(n + 1, 0);
        weighting.assign(n + 1, 0);
        for(int i = 1;i <= n;++i){
            prefix[i] = prefix[i - 1] + num[i];
            weighting[i] = weighting[i - 1] + (long long)num[i] * i;
        }

        solve(1, n, 0);
        cout << ans << '\n';
    }
}