#include<bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int a[maxn], tree[4 * maxn];

void build(int pos, int tl, int tr){
    if (tl == tr){
        tree[pos] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(2 * pos, tl, tm);
        build(2 * pos + 1, tm + 1, tr);
        tree[pos] = max(tree[2 * pos + 1], tree[2 * pos]);
    }
}

int query(int pos, int tl, int tr, int val){
    if (tl == tr){
        return tl;
    }
    int tm = (tl + tr) / 2;
    if (val <= tree[2 * pos]){
        return query(2 * pos, tl, tm, val);
    } else {
        return query(2 * pos + 1, tm + 1, tr, val);
    }
}

void update(int pos, int tl, int tr, int idx, int val){
    if (tl == idx && tr == idx){
        tree[pos] -= val;
    } else {
        int tm = (tl + tr) / 2;
        if (idx <= tm){
            update(2 * pos, tl, tm, idx, val);
        } else {
            update(2 * pos + 1, tm + 1, tr, idx, val);
        }
        tree[pos] = max(tree[2 * pos], tree[2 * pos + 1]);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(1, 1, n);
    for (int i = 0; i < m; i++){
        int val;
        cin >> val;
        if (val > tree[1]){
            cout << "0 ";
            continue;
        }
        int idx = query(1, 1, n, val);
        update(1, 1, n, idx, val);
        cout << idx << " ";
    }
    return 0;
}
