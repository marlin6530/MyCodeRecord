//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n)
    {
        int map[150][150]{0};
        int left, right, top, bottom;
        int counter = 0;

        for(int i = 0;i < n;++i){
            cin >> left >> right >> bottom >> top;

            for(int j = left;j < right;++j){
                for(int k = bottom;k < top;++k){
                    if(map[j][k] == 0)
                        counter++;
                    map[j][k]++;
                }
            }
        }
        cout << counter << "\n";
    }


    return 0;
}