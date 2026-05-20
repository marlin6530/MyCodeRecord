#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<utility>
#include<cstring>

using namespace std;

#define int long long
#define pb push_back

signed main(){
    int t;
    cin >> t;
    while(t--)
    {
        int r;
        cin >> r;
        vector<int> vec;
        int tmp;
        for(int i = 0;i < r;++i){
            cin >> tmp;
            vec.push_back(tmp);
        }
        sort(vec.begin(), vec.end());
        int mid = vec[r/2];
        int ans = 0;
        for(int i: vec){
            ans += abs(i - mid);
        }
        cout << ans << '\n';
    }
}