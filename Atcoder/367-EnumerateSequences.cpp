#include<bits/stdc++.h>
using namespace std;

int N, K;
vector<int> R;
vector<int> vec;

void dfs(int depth, int sum){
    if(depth == N){
        if(sum % K == 0){
            for(int i = 0;i < N;++i){
                cout << vec[i] << (i == N - 1 ? "" : " ");
            }
            cout << '\n';
        }
        return;
    }

    for(int i = 1;i <= R[depth];++i){
        vec.push_back(i);
        dfs(depth + 1, sum + i);
        vec.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    R.clear();
    vec.clear();

    cin >> N >> K;
    for(int i = 0;i < N;++i){
        int buf;
        cin >> buf;
        R.push_back(buf);
    }

    dfs(0, 0);
    
    return 0;
}