#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int lds1(vector<int> &v){
    int n = v.size();
    int best = 1;
    vector<int> dp(n, 1);
    for(int i = 0;i < n;++i){
        for(int j = 0;j < i;++j){
            if(v[j] > v[i]) dp[i] = max(dp[i], dp[j]+1);
        }
        best = max(best, dp[i]);
    }
    return best;
}

int lds2(vector<int> &v){
    vector<int> tail;
    tail.push_back(v[0]);
    for(int i = 1;i < (int)v.size();++i){
        auto it = upper_bound(tail.begin(), tail.end(), v[i], greater<int>());
        if(it == tail.end()){
            tail.push_back(v[i]);
        }else{
            *it = v[i];
        }
    }

    return tail.size();
}

int main(){
    int n, cnt = 0;
    while(1)
    {
        cin >> n;
        if(n == -1) break;
        vector<int> v;
        v.push_back(n);
        while(1){
            cin >> n;
            if(n == -1) break;
            v.push_back(n);
        }

        if(cnt++) cout << '\n';
        cout << "Test #" << cnt << ":\n  maximum possible interceptions: ";
        cout << lds2(v) << "\n";
    }
}