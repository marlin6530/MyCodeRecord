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
        int n, k;
        cin >> n >> k;

        if (k == n - 1 && n == 4) {
            cout << -1 << endl;
            continue;
        }

        if (k < n - 1) {
            cout << k << " " << n - 1 << endl;
            if (k > 0) cout << 0 << " " << n - 1 - k << endl;
            for (int i = 1; i < n / 2; i++) {
                if (i == k || i == n - 1 - k) continue;
                cout << i << " " << n - 1 - i << endl;
            }
        } 
        else { 
            cout << n - 1 << " " << n - 2 << endl;
            cout << 1 << " " << 3 << endl;
            cout << 0 << " " << n - 4 << endl;
            for (int i = 2; i < n / 2; i++) {
                if (i == 3) continue; 
                cout << i << " " << n - 1 - i << endl;
            }
        }
    }
    
}