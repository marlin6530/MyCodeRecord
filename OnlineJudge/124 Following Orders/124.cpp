#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main(){
    string line1, line2;
    while(getline(cin, line1))
    {
        stringstream ss1(line1);
        vector<char> v;
        char ch;
        while(ss1 >> ch){
            v.push_back(ch);
        }
        getline(cin, line2);
        stringstream ss2(line2);
        
    }
}