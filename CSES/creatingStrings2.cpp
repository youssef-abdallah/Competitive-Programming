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

int freq[26];

int main()
{
    vector<int> fact(maxn);
    fact[0] = 1;
    for (ll i = 1; i < maxn; i++){
        fact[i] = (i * fact[i - 1]) % mod;
    }
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++){
        freq[s[i] - 'a']++;
    }
    ll num = fact[n];
    ll denom = 1;
    for (int i = 0; i < 26; i++){
        denom *= fact[freq[i]];
        denom %= mod;
    }
    ll ans = num * binpow(denom, mod - 2, mod);
    ans %= mod;
    cout << ans;
    return 0;
}
