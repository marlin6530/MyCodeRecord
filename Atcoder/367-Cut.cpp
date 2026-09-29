#include<bits/stdc++.h>
//#include<iostream>
using namespace std;

#define int long long

signed main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   string s;
   cin >> s;

   while(!s.empty() && s.back() == '0'){
        s.pop_back();
   }
   if(!s.empty() && s.back() == '.'){
        s.pop_back();
   }

   cout << s << '\n';
}