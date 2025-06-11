//Time Complexity: O()

//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    int a, b;
    while(cin >> a >> b){
        while(a % b != 0){
            int tmp = a % b;
            a = b;
            b = tmp;
        }
        cout << b << '\n';
    }
    return 0;
}