//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

#define int long long

signed main(){
    string s;
    int n;
    int cnt = 1;
    while(cin >> n)
    {
        vector<int> num(n);
        for(int i = 0;i < n;++i){
            cin >> num[i];
        }
        cin.ignore();
        getline(cin, s);
        
        vector<bool> nextN(n);
        bool status = 0;
        for(int i = n - 1;i >= 0;--i){
            nextN[i] = status;
            if(num[i] < 0) status = 1;
        }

        int better = -1, total = 1, pos = -1;
        bool hasAns = 0;
        for(int i = 0;i < n;++i){
            total *= num[i];
            if(total > 0){
                better = max(better, total);
                hasAns = 1;
            }
            else if(total < 0 && nextN[i] == 1){
                if(pos == -1) pos = i;
                better = max(better, total);
                hasAns = 1;
            } 
            else if(total < 0 && pos != -1){
                total /= num[pos];
                better = max(better, total);
                hasAns = 1;
            } 
            else{
                total = 1;
            }
        }
        
        if(!hasAns) better = 0;
        cout << "Case #" << cnt++ << ": The maximum product is " << better << ".\n\n";

    }
}