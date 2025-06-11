//Time Complexity: O()

//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    int n, l;
    while(cin >> n && n != 0)
    {
        vector<vector<int>> node(n);
        vector<int> color(n, -1);
        bool isBicoloring = 1;

        cin >> l;
        int a, b;
        for(int i = 0;i < l;++i){
            cin >> a >> b;
            node[a].push_back(b);
            node[b].push_back(a);
        }

        stack<int> st;
        color[0] = 0;
        st.push(0);
        while(!st.empty() && isBicoloring){
            int cnt = st.top();
            st.pop();

            for(int i = 0;i < node[cnt].size();++i){
                int n = node[cnt][i];
                if(color[n] == color[cnt]){
                    isBicoloring = 0;
                    break;
                }
                else if(color[n] == -1){
                    if(color[cnt] == 1)
                        color[n] = 0;
                    else 
                        color[n] = 1;
                    st.push(n);
                }
            }
        }

        if(isBicoloring){
            cout << "BICOLORABLE.\n";
        }else{
            cout << "NOT BICOLORABLE.\n";
        }
    }
    return 0;
}