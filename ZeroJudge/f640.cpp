//Time Complexity: O()

//#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

int f();
int g();
int h();

int main(){
    string n;
    int ans;
    cin >> n;
    if(n == "f"){
        ans = f();
    }else if(n == "g"){
        ans = g();
    }else if(n == "h"){
        ans = h();
    }
    cout << ans << '\n';

    return 0;
}

int f(){
    string n;
    int num;
    cin >> n;

    if(n == "f"){
        num = f();
    }else if(n == "g"){
        num = g();
    }else if(n == "h"){
        num = h();
    }else{
        num = stoi(n);
    }

    return 2 * num - 3;
}

int g(){
    string n;
    int num[2];
    for(int i=0;i<2;++i){
        cin >> n;

        if(n == "f"){
            num[i] = f();
        }else if(n == "g"){
            num[i] = g();
        }else if(n == "h"){
            num[i] = h();
        }else{
            num[i] = stoi(n);
        }
    }
    return 2 * num[0] + num[1] - 7;
}

int h(){
    string n;
    int num[3];
    for(int i=0;i<3;++i){
        cin >> n;

        if(n == "f"){
            num[i] = f();
        }else if(n == "g"){
            num[i] = g();
        }else if(n == "h"){
            num[i] = h();
        }else{
            num[i] = stoi(n);
        }
    }
    return 3 * num[0] - 2 * num[1] + num[2];
}