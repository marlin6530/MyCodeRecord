#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define f first
#define s second

int cross(pii a, pii b, pii c){
    return (b.f - a.f) * (c.s - a.s) - (c.f - a.f) * (b.s - a.s);
}

signed main() {
    int n;
    cin >> n;
    vector<pii> point;
    for(int i = 0;i < n;++i){
        int x, y;
        cin >> x >> y;
        point.push_back(make_pair(x, y));
    }
    
    //Andrew
    sort(point.begin(), point.end());
    int cnt = 0;
    vector<pii> ans;
    //下
    for(int i = 0;i < n;++i){
        while(ans.size() >= 2 && cross(ans[ans.size()-2], ans[ans.size()-1], point[i]) < 0){
            ans.pop_back();
        }
        ans.push_back(point[i]);
    }
    //上
    int t = ans.size();
    for(int i = n - 2;i >= 0;--i){
        while(ans.size() - t >= 2 && cross(ans[ans.size()-2], ans[ans.size()-1], point[i]) < 0){
            ans.pop_back();
        }
        ans.push_back(point[i]);
    }
    ans.pop_back();
    
    cout << ans.size() << '\n';
    for(pii i: ans){
        cout << i.f << " " << i.s << '\n';
    }

    return 0;
}
