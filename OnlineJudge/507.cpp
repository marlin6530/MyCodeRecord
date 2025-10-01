//WA
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int route = 1;route <= t;++route)
    {
        int n;
        cin >> n;
        int best = 0, ans1 = 0, ans2 = 0;
        int start = 0, sum = 0;
        int a;
        for(int i = 1;i < n;++i){
            cin >> a;
            sum += a;
            if(sum < 0){
                sum = 0;
                start = i;
            }
            else if(sum > best || (sum == best && i - start > ans2 - ans1)){
                best = sum;
                ans1 = start;
                ans2 = i;
            }
        }
        if (best > 0)
            cout << "The nicest part of route " << route << " is between stops " << ans1+1 << " and " << ans2+1 << endl;
        else
            cout << "Route " << route << " has no nice parts" << endl;
    }
}