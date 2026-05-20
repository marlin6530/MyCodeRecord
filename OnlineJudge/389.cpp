#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back

char toChar(int n){
    string s = "0123456789ABCDEF";
    return s[n];
}

int toValue(char c){
    if(c >= '0' && c <= '9'){
        return c - '0';
    }
    if(c >= 'A' && c <= 'F'){
        return c - 'A' + 10;
    }
    return 0;
}

int to10(string s, int x){
    int total = 0;
    for(int i = 0;i < s.size();++i){
        total += toValue(s[i]) * pow(x, i);
    }

    return total;
}

string toTarget(int n, int y){
    string s = "";
    while(n > 0){
        int tmp = n % y;
        s += toChar(tmp);
        n /= y;
    }

    reverse(s.begin(), s.end());
    return s;
}

signed main(){
    int x, y;
    string str;
    while(cin >> str >> x >> y)
    {
        reverse(str.begin(), str.end());
        int num = to10(str, x);
        if(num == 0){
            str = "0";
        }
        else{
            str = toTarget(num, y);
            if(str.size() > 7) str = "ERROR";
        }

        cout << setw(7) << str << '\n';
    }
    return 0;
}