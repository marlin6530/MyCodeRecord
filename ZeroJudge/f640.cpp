#include<bits/stdc++.h>
using namespace std;

int cal(){
    string ch;
    cin >> ch;
    if(ch == "f"){
        int x = cal();
        return 2 * x - 3;
    }
    if(ch == "g"){
        int x = cal();
        int y = cal();
        return 2 * x + y - 7;
    }
    if(ch == "h"){
        int x = cal();
        int y = cal();
        int z = cal();
        return 3 * x - 2 * y + z;
    }
    return stoi(ch);
}

int main(){
    cout << cal() << '\n';
    return 0;
}