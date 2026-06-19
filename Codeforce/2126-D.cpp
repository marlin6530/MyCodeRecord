#include<bits/stdc++.h>

using namespace std;

// 定義一個結構（Structure）來儲存每間賭場的資訊
struct Casino {
    long long l;
    long long r;
    long long real;
};

// 排序的自訂比較函數：按照左界 l 由小到大排序
bool compareCasino(const Casino& a, const Casino& b) {
    return a.l < b.l;
}

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    
    vector<Casino> casinos(n);
    for (int i = 0; i < n; i++) {
        cin >> casinos[i].l >> casinos[i].r >> casinos[i].real;
    }
    
    // 步驟 1：按左界 l 進行升序排序
    sort(casinos.begin(), casinos.end(), compareCasino);
    
    // 步驟 2：貪心遍歷所有賭場
    long long current_coins = k;
    for (int i = 0; i < n; i++) {
        // 如果當前的金幣大於等於賭場的左界，代表有機會觸發
        if (current_coins >= casinos[i].l) {
            current_coins = max(current_coins, casinos[i].real);
        }
    }
    
    // 輸出最終能獲得的最大金幣數
    cout << current_coins << "\n";
}

int main() {
    // 提升 C++ 輸入輸出（I/O）的效能，避免因資料量大而超時
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}