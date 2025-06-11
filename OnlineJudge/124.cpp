//(C: Completed, P: In Progress, N: Not Started, D: Debugging)
//Status: C

#include<bits/stdc++.h>
//#include<iostream>
using namespace std;

vector<char> node;
map<char, vector<char>> graph;
map<char, int> indegree;
map<char, bool> visited;
//queue<string> solution;
vector<char> ans;

void dfs(){
    if(ans.size() == node.size()){
        string s;
        for(char i: ans){
            s += i;
        }
        cout << s << '\n';
        return;
    }

    for(auto now: node){
        if(!visited[now] && indegree[now] == 0){
            visited[now] = true;
            for(auto neighbor: graph[now]){
                indegree[neighbor]--;
            }
            ans.push_back(now);

            dfs();

            ans.pop_back();
            for(auto neighbor: graph[now]){
                indegree[neighbor]++;
            }
            visited[now] = false;
        }
    }
}

int main(){
    string line1, line2;
    bool firstLine = true;
    while(getline(cin, line1)){
        getline(cin, line2);
        stringstream ss1(line1);
        char ch;
        while(ss1 >> ch){
            node.push_back(ch);

            visited[ch] = false;
        }
        sort(node.begin(), node.end());
        stringstream ss2(line2);
        char u, v;
        while(ss2 >> u >> v){
            graph[u].push_back(v);
            indegree[v]++;
        }

        if(!firstLine) cout << '\n';
        dfs();
        firstLine = false;

        node.clear();
        graph.clear();
        indegree.clear();
        visited.clear();
        ans.clear();
    }
}