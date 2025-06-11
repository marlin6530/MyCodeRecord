#include <bits/stdc++.h>
using namespace std;

map <char, int> letters;
string Message;
int a,b;
int mesCode[1000], encrypt[1000];

void comput(){
    for(int i = 0; i < Message.size(); ++i){
        int mod = (mesCode[i] * a + b) % 26;
        encrypt[i] = mod;
    }
    cout << Message << '\n';
    for(int i = 0; i < Message.size(); ++i){
        if(isupper(Message[i])){
            cout << encrypt[i] << ' ';
            mesCode[i] = encrypt[i];
        }
        else{
            cout << '\t';
        }
    }
    cout << '\n';
}

void inputF(){
    cout << "\nf(p) = ap + b (mod26)";
    cout << "\nInput a:";
    cin >> a;
    cout << "\nInput b:";
    cin >> b;
    cin.ignore();
}

void inputMes(string Message){
    //getline(cin, Message);
    for(int i = 0; i < Message.size(); ++i){
        if(isupper(Message[i])){
            mesCode[i] = letters[Message[i]];
        }
    }
}

void letterCode(){
    for(int i = 0; i < 26; ++i){
        cout << char('A' + i) << " = " << i << '\n';
    }
}

int main(){
    for(int i = 0 ; i < 26 ; ++i){
        letters['A'+ i] = i;
    }
    int n;
    getline(cin, Message);
    while(cin >> n && n){
        inputMes(Message);
        inputF();
        comput();
    }
    return 0;
}