//(C: Completed, P: In Progress, N: Not Started, D: Debugging)
//Status: N

#include<bits/stdc++.h>
//#include<iostream>
using namespace std;

string s1, s2;
vector<deque<char>> ans;

void dfs(int cnt, stack<char> stk, string tmp, deque<char> op){
    if(tmp.size() == s2.size()){
        if(tmp == s2){
            ans.push_back(op);
        }
        return;
    }
    //push
    if(cnt < s1.size()){
        stk.push(s1[cnt]);
        op.push_back('i');
        dfs(cnt + 1, stk, tmp, op);
        op.pop_back();
        stk.pop();
    }
    
    //pop
    if(!stk.empty()){
        op.push_back('o');
        char ch = stk.top();
        int pos = tmp.size();
        if(ch != s2[pos]){
            return;
        }
        stk.pop();
        dfs(cnt, stk, tmp + ch, op);
        stk.push(ch);
        op.pop_back();
    }
}

int main(){
    while(cin >> s1){
        cin >> s2;
        cout << "[\n";
        //start dfs
        if(s1.size() == s2.size()){
            deque<char> op;
            op.push_back('i');
            string tmp = "";
            int cnt = 1;
            stack<char> stk;
            stk.push(s1[0]);
            dfs(cnt, stk, tmp, op);

            for(int i = 0;i < ans.size();++i){
                while(!ans[i].empty()){
                    cout << ans[i].front();
                    if(ans[i].size() != 1) cout << " ";
                    ans[i].pop_front();
                }
                cout << "\n";
            }
            
            ans.clear();
        }
        cout << "]\n";
    }
}