#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;
int tree[4 * maxn], interval[4 * maxn];

void add(int pos, int tl, int tr, int idx, int val){
    interval[pos]++;
    if (tl == idx && tr == idx) {
        tree[pos] = val;
    } else {
        int tm = (tl + tr) >> 1;
        if (idx <= tm){
            add(2 * pos, tl, tm, idx, val);
        } else {
            add(2 * pos + 1, tm + 1, tr, idx, val);
        }
    }
}

int del(int pos, int tl, int tr, int idx){
    interval[pos]--;
    if (tl == tr)
        return tree[pos];
    int tm = (tl + tr) >> 1;
    if (idx <= interval[2 * pos]){
        return del(2 * pos, tl, tm, idx);
    } else {
        return del(2 * pos + 1, tm + 1, tr, idx - interval[2 * pos]);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int a;
        cin >> a;
        add(1, 1, n, i, a);
    }
    for (int i = 1; i <= n; i++){
        int a;
        cin >> a;
        cout << del(1, 1, n, a) << " ";
    }
    return 0;
}
