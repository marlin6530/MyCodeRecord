#include<iostream>
#include<deque>
#include<string>
#include<iterator>

using namespace std;

int main(){
    string input;
    while(getline(cin, input))
    {
        deque<char> out;
        deque<char>::iterator it = out.begin();
        for(char c : input){
            if(c == '['){
                it = out.begin();
            }else if(c == ']'){
                it = out.end();
            }else{
                it = out.insert(it, c);
                ++it;   
            }
        }

        for(it = out.begin();it != out.end(); ++it){
            cout << *it;
        }
        cout << "\n";
    }
    return 0;
}