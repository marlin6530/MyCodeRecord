#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back

int ans[15];

void cal(){
    for(int i = 1;i < 14;++i){
        int m = i + 1;
        while(1){
            int pos = 0;
            int len = i * 2;
            bool hasAns = 0;

            while(!hasAns){
                pos = (pos + m - 1) % len;
                if(pos < i){
                    break;
                }
                --len;
                if(len == i) hasAns = 1;
            }
            if(hasAns){
                ans[i] = m;
                break;
            }
            ++m;
        }
    }
    return;
}

signed main(){
    int k;
    cal();
    while(cin >> k && k){
        cout << ans[k] << '\n';
    }   
}