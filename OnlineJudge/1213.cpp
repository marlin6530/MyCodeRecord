//(C: Completed, P: In Progress, N: Not Started, D: Debugging)
//Status: N

#include<bits/stdc++.h>
using namespace std;

#define int long long

vector<int> prime;

signed main(){
    int n, k;
    vector<bool> isPrime(1125, 1);
    for(int i = 3;i * i <= 1120;i += 2){
        if(isPrime[i]){
            for(int j = i * i;j <= 1120;j += i){
                isPrime[j] = 0;
            }
        }
    }
    prime.push_back(0);
    prime.push_back(2);
    for(int i = 3;i <= 1120;i +=2){
        if(isPrime[i]) prime.push_back(i);
    }

    while(cin >> n >> k)
    {
        if(n == 0 && k == 0)
            break;
        vector<vector<int> dp(n + 1, vector<int>(k + 1, 1));
        int s = prime.size();
        for(int i = 1;i < s;++i){
            for(j = 0;j < prime)
        }
    }
}