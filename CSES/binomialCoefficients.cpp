#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const int maxn = 1e6 + 5;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main()
{
    int n;
    vector<int> fact(maxn);
    fact[0] = 1;
    for (ll i = 1; i < maxn; i++){
        fact[i] = (i * fact[i - 1]) % mod;
    }
    cin >> n;
    while(n--){
        int a, b;
        cin >> a >> b;
        ll num = fact[a];
        ll denom = fact[a - b];
        denom *= fact[b];
        denom %= mod;
        ll ans = num * binpow(denom, mod - 2, mod);
        ans %= mod;
        cout << ans << endl;
    }
    return 0;
}
