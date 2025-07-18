//(C: Completed, P: In Progress, N: Not Started, D: Debugging)
//Status: C

#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int m;
    int cnt = 0;
    while(cin >> n >> m && (n || m)){
        list<int> l;
        for(int i = 0;i < min(n, m);++i){
            l.push_back(i + 1);
        }

        cout << "Case " << ++cnt << ":\n";

        for(int k = 0;k < m;++k){
            char ch;
            cin >> ch;
            if(ch == 'N'){
                int tmp = l.front();
                l.pop_front();
                cout << tmp << '\n';
                l.push_back(tmp);
            }else{
                int x;
                cin >> x;
                auto it = find(l.begin(), l.end(), x);
                if(it != l.end()){
                    l.erase(it);
                }
                l.push_front(x);
            }
        }
    }
}