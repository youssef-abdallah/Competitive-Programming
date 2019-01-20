#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll fact[1000010], dp[1000010];

int main()
{
    ll n;
    cin >> n;
    fact[0] = 1;
    for(ll i = 1; i <= 1000000; i++){
        fact[i] = i * fact[i - 1];
        fact[i] %= mod;
    }
    ll ans = fact[n];
    dp[2] = 0;
    for(ll i = 3; i <= n; i++){
        dp[i] = dp[i - 1] + fact[i - 1] - 1;
        dp[i] *= i;
        dp[i] %= mod;
    }
    ans += dp[n];
    ans %= mod;
    cout << ans;
    return 0;
}
