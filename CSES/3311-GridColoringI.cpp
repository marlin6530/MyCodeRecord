//(C: Completed, P: In Progress, N: Not Started, D: Debugging)
//Status: C

#include<bits/stdc++.h>
//#include<iostream>
using namespace std;

int main(){
    int n, m;
    char graph[550][550];
    char alpha[4] = {'A', 'B', 'C', 'D'};
    while(cin >> n >> m){
        for(int i = 0;i < n;++i){
            for(int j = 0;j < m;++j){
                cin >> graph[i][j];
            }
        }
        char ans[550][550];
        for(int i = 0;i < n;++i){
            for(int j = 0;j < m;++j){
                map<char, bool> val;
                for(int k = 0;k < 4;++k) val[alpha[k]] = true;
                val[graph[i][j]] = false;
                if(i > 0){
                    val[ans[i - 1][j]] = false;
                }
                if(j > 0){
                    val[ans[i][j - 1]] = false;
                }
                for(int k = 0;k < 4;++k){
                    if(val[alpha[k]] == true){
                        ans[i][j] = alpha[k];
                        break;
                    }
                }
            }
        }

        for(int i = 0;i < n;++i){
            for(int j = 0;j < m;++j){
                cout << ans[i][j];
            }
            cout << '\n';
        }
    }
}