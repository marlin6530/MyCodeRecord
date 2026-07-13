//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define int long long

const int MAX = 200500;
int n, q;
int arr[MAX];
int tree[MAX * 4], lazy[MAX * 4];

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

void pushDown(int node, int l, int r){
    if(lazy[node] != 0){
        int mid = (l + r) / 2;
        int leftLen = mid - l + 1;
        int rightLen = r - mid;

        tree[node * 2] += lazy[node] * leftLen;
        lazy[node * 2] += lazy[node]; 

        tree[node * 2 + 1] += lazy[node] * rightLen;
        lazy[node * 2 + 1] += lazy[node]; 

        lazy[node] = 0;
    }
}

void update(int node, int l, int r, int ql, int qr, int val){
    if(qr < l || ql > r) return;

    if(ql <= l && qr >= r){
        tree[node] += val * (r - l + 1);
        lazy[node] += val;
        return;
    }

    pushDown(node, l, r);
    int mid = (l + r) / 2;
    update(node * 2, l, mid, ql, qr, val);
    update(node * 2 + 1, mid + 1, r, ql, qr, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int l, int r, int pos){
    if(l == r) return tree[node];

    pushDown(node, l, r);
    int mid = (l + r) / 2;
    if(pos <= mid) return query(node * 2, l, mid, pos);
    else return query(node * 2 + 1, mid + 1, r, pos);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for(int i = 0;i < n;++i){
        cin >> arr[i];
    }
    build(1, 0, n - 1);
    while(q--)
    {
        int op;
        cin >> op;
        if(op == 1){
            int a, b, u;
            cin >> a >> b >> u;
            update(1, 0, n - 1, a - 1, b - 1, u);
        }
        else{
            int k;
            cin >> k;
            cout << query(1, 0, n - 1, k - 1) << '\n';
        }
    }
}