#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    string s;
    int t;
    cin >> t;
    cin.ignore();
    bool first = 1;
    getline(cin, s);
    while(t--)
    {
        vector<int> num;
        while(getline(cin, s)){
            if(s == "") break;
            num.push_back(stoi(s));
        }
        
        int n = num.size();
        vector<int> tail;
        vector<int> idx;
        vector<int> prev(n, -1);

        for(int i = 0;i < n;++i){
            int x = num[i];
            auto it = lower_bound(tail.begin(), tail.end(), x);
            int pos = it - tail.begin();

            if(it == tail.end()){
                tail.push_back(x);
                idx.push_back(i);
            }
            else{
                tail[pos] = x;
                idx[pos] = i;
            }
            if(pos > 0) prev[i] = idx[pos - 1];
        }

        int l = tail.size();
        if(!first) cout << '\n';
        first = 0;
        cout << "Max hits: " << l << '\n';

        vector<int> ans;
        int cur = idx[l - 1];
        while(cur != -1){
            ans.push_back(num[cur]);
            cur = prev[cur];
        }
        reverse(ans.begin(), ans.end());
        for(int x: ans){
            cout << x << '\n';
        }
    }
}