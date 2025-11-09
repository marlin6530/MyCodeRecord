#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> h(n), w(n);
vector<int> lis(n+1), lds(n+1);

int LIS(){
    int ansLis = -1;
    for(int i = 0;i < n;++i){
        for(int j = 0;j < i;++j){
            if(h[j] < h[i]){
                lis[i] = max(lis[i], lis[j] + w[i]);
            }
        }
        ansLis = max(ansLis, lis[i]);
    }

    return ansLis;
}

int LDS(){
    int ansLds = -1;
    for(int i = 0;i < n;++i){
        for(int j = 0;j < i;++j){
            if(h[j] > h[i]){
                lds[i] = max(lds[i], lds[j] + w[i]);
            }
        }
        ansLds = max(ansLds, lds[i]);
    }

    return ansLds;
}

int main(){
    int t;
    cin >> t;
    for(int k = 1;k <= t;++k)
    {
        cin >> n;

        for(int i = 0;i < n;++i){
            cin >> h[i];
        }
        for(int i = 0;i < n;++i){
            cin >> w[i];
            lis[i] = lds[i] = w[i];
        }

        int ansLis = LIS();
        int ansLds = LDS();

        cout << "Case " << k << ". ";
        if (ansLis >= ansLds) cout << "Increasing (" << ansLis << "). Decreasing (" << ansLds << ").\n";
		else cout << "Decreasing (" << ansLds << "). Increasing (" << ansLis << ").\n";
    }
}