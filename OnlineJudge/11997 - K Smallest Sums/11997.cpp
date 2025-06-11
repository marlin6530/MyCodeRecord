//Time Complexity: O()

//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;

struct node{
    int val;
    int index;

    node(int _val, int _index):
        val(_val), index(_index){}

    bool operator<( const node& right) const{
        return val > right.val;
    }
};

int main(){
    int k;
    while(cin >> k){
        vector<int> a;
        int n;
        for(int i = 0;i < k;++i){
            cin >> n;
            a.push_back(a);
        }
        sort(a.begin(), a.end());

        for(int i = 1;i < k;++i)
        {
            vector<int> b;
            priotity_queue<node, vector<node>, greater<node>>;
            for(int j = 0;j < k;++j){
                cin >> n;
                b.push_back(n);
            }
            sort(b.begin(), b.end());
        }
    }
    return 0;
}