#include<bits/stdc++.h>
using namespace std;

int main(){
    int s, m, d;
    cin >> m >> d;
    s = (m*2+d) % 3;
    if(s==0){
        cout << "普通\n";
    }else if(s==1){
        cout << "吉\n";
    }else
        cout << "大吉\n";
    return 0;
}