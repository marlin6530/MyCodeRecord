#include<bits/stdc++.h>
using namespace std;

int m;

bool cmp(const int &x, const int &y){
    //餘數不同：
    if(x % m != y % m){
        //餘數大的排前面
        return x % m < y % m;
    }
    //餘數一樣：
    //二奇
    if(x % 2 && y % 2){
        return x > y;
    }
    //二偶
    if(x % 2 == 0 && y % 2 == 0){
        return x < y;
    }
    //一奇一偶
    return x % 2;
}

int main(){
    int n;
    while(cin >> n >> m)
    {
        if(n == 0 && m == 0){
            cout << "0 0\n";
            break;
        }
        vector<int> v(n);
        for(int i = 0;i < n;++i){
            cin >> v[i];
        }
        sort(v.begin(), v.end(), cmp);
        cout << n << " " << m << '\n';
        for(auto ans:v){
            cout << ans << '\n';
        }
    }
}