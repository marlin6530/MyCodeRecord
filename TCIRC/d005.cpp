//(C: Completed, P: In Progress, N: Not Started, D: Debugging)
//Status: C

#include<bits/stdc++.h>
//#include<iostream>
using namespace std;

int ans;
int n;
string s;
int idx;

void count(int n){
    char c = s[idx++];
    if(c == '2'){
        count(n / 2);
        count(n / 2);
        count(n / 2);
        count(n / 2);
    }else if(c == '1'){
        ans += n * n;
    }
}

int main(){
    while(cin >> s >> n){
        idx = ans = 0;
        count(n);
        cout << ans << '\n';
    }
}