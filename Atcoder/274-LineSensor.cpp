//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, h, w;
    char in;
    while(cin >> h >> w)
    {
        vector< vector<char> > vec;

        for(int i = 0;i < h;++i){
            vector<char> tmp;
            for(int j = 0;j < w;++j){
                cin >> in;
                tmp.push_back(in);
            }
            vec.push_back(tmp);
        }
    
        for(int j = 0;j < w;++j){
            int counter = 0;
            for(int i = 0;i< h;++i){
                if(vec[i][j] == '#')
                    counter++;
            }
            cout << counter << " ";
        }
        cout << "\n";
    }
    


    return 0;
}