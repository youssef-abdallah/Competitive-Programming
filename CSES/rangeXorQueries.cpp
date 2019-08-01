#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;

int tree[4 * maxn], a[maxn];

void build(int pos, int tl, int tr){
    if (tl == tr){
        tree[pos] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(2 * pos, tl, tm);
        build(2 * pos + 1, tm + 1, tr);
        tree[pos] = tree[2 * pos] ^ tree[2 * pos + 1];
    }
}

int query(int pos, int tl, int tr, int l, int r){
    if (tl > tr || tl > r || tr < l) return 0;
    if (tl >= l && tr <= r)
        return tree[pos];
    int tm = (tl + tr) / 2;
    return query(2 * pos, tl, tm, l, r) ^ query(2 * pos + 1, tm + 1, tr, l, r);
}



int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    build(1, 0, n - 1);
    while(q--){
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << query(1, 0, n - 1, l, r) << endl;
    }
    return 0;
}

