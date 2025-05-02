//Time Complexity: O()

#include<bits/stdc++.h>
using namespace std;

int m(int i){
    if(i == 0) return 1;
    // int sum = 1;
    // sum = m(i - 1) * i;
    return m(i - 1) * i;
}

int main(){
    int n;
    while(cin >> n){
        cout << n << "! =";
        for(int i = n;i > 1;--i){
            cout << " " << i << " *";
        }
        cout << " 1  = ";
        cout << m(n) << "\n";
    }   

    return 0;
}