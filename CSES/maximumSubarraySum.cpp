#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll Inf = 1e18 + 5;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<ll> pre(n + 1);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        pre[i + 1] = pre[i] + ll(a[i]);
    }
    ll mn = 0;
    ll ans = -Inf;
    for (int i = 1; i <= n; i++){
        ans = max(ans, pre[i] - mn);
        mn = min(pre[i], mn);
    }
    cout << ans;
    return 0;
}
