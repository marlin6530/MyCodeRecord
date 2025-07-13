//(C: Completed, P: In Progress, N: Not Started, D: Debugging)
//Status: C

#include<bits/stdc++.h>
//#include<iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        int map[105][105];
        for(int i = 0;i < n;++i){
            for(int j = 0;j < n;++j){
                vector<bool> valid(500, true);
                for(int k = 0;k < i;++k){
                    valid[map[k][j]] = false;
                }
                for(int k = 0;k < j;++k){
                    valid[map[i][k]] = false;
                }
                for(int num = 0;num <= 500;++num){
                    if(valid[num]){
                        map[i][j] = num;
                        break;
                    }
                }
            }
        }
        for(int i = 0;i < n;++i){
            for(int j = 0;j < n;++j){
                cout << map[i][j] << " ";
            }
            cout << '\n';
        }
    }
}