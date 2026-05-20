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
    int a, b;
    while(cin >> a >> b)
    {
        if(!a && !b) break;
        int carry = 0, count = 0;
        while(a || b){
            if(a % 10 + b % 10 + carry > 9){
                carry = 1;
                ++count;
            }
            else carry = 0;
            a /= 10;
            b /= 10;
        }

        if(count == 0) cout << "No carry operation.\n";
        else if(count == 1) cout << "1 carry operation.\n";
        else cout << count << " carry operations.\n";
    }
}