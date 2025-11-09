#include<iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, f;
        cin >> n >> f;
        for(int i = 0;i < f;++i){
            if(i) cout << "\n";
            for(int j = 1;j <= n;++j){
                for(int k = 0;k < j;++k){
                    cout << j;
                }
                cout << "\n";
            }
            for(int j = n - 1;j >= 0;--j){
                for(int k = 0;k < j;++k){
                    cout << j;
                }
                cout << "\n";
            }
        }
    }
}