//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define int long long

const int MAX = 200005;
int tree[MAX * 4] = {};
int arr[MAX];
int n, q;

void build(int node, int l, int r){
    if(l == r){
        tree[node] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update(int node, int l, int r, int idx, int val){
    if(l == r){
        tree[node] = val;
        return;
    }
    int mid = (l + r) / 2;
    if(idx <= mid) update(node * 2, l, mid, idx, val);
    else update(node * 2 + 1, mid + 1, r, idx, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int l, int r, int ql, int qr){
    if(qr < l || ql > r) return 0;
    if(ql <= l && qr >= r) return tree[node];
    int mid = (l + r) / 2;
    return query(node * 2, l, mid, ql, qr) + query(node * 2 + 1, mid + 1, r, ql, qr);
}

signed main(){
    cin >> n >> q;
    for(int i = 0;i < n;++i){
        cin >> arr[i];
    }
    build(1, 0, n - 1);
    while(q--)
    {
        int op, a, b;
        cin >> op >> a >> b;
        if(op == 1) update(1, 0, n - 1, a - 1, b);
        else cout << query(1, 0, n - 1, a - 1, b - 1) << '\n';
    }
}