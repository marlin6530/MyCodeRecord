#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<utility>
#include<cstring>
#include<iomanip>

using namespace std;

#define int long long
#define pb push_back

signed main(){
    double n, a;
    while(cin >> n >> a)
    {
        if(!n) break;

        double x, y;
        double cnt = 0;
        for(int i = 0;i < n;++i){
            cin >> x >> y;
            double dist1 = (x - a) * (x - a);
            double dist2 = (y - a) * (y - a);
            double x2 = x*x;
            double y2 = y*y;
            double a2 = a*a;
            if(x2 + y2 <= a2 && dist1 + y2 <= a2 && dist1 + dist2 <= a2 && x2 + dist2 <= a2) ++cnt;
        }
        
        cout << fixed << setprecision(5) << cnt * a * a / n << '\n';
    }
    
}