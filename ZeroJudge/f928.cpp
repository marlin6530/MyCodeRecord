//Time Complexity: O()

//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int b[1500];
void boom(int pos);
int n;

int main(){
    cin >> n;
    for(int i = 0;i < n;++i){
        cin >> b[i];
    }
    int pos;
    cin >> pos;
    boom(pos);
    for(int i =0;i < n;++i){
        cout << b[i] << " ";
    }

    return 0;
}

void boom(int pos){
    if(b[pos] == 1){
        b[pos] = 0;
    }else if(b[pos] == 2){
        b[pos] = 0;
        if(pos - 1 >= 0) boom(pos - 1);
        if(pos + 1 < n) boom(pos + 1);
    }else if(b[pos] >= 3){
        int k = b[pos];
        b[pos] = 0;
        if(pos - k >= 0){
            boom(pos - k);
            if(pos - 2*k >= 0) 
                boom(pos - 2*k);
        } 
        if(pos + k < n){
            boom(pos + k);
            if(pos + 2*k < n) 
                boom(pos + 2*k);
        }
    }
    return;
}