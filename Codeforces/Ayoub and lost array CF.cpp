#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int maxn = 2e5 + 10;
typedef long long ll;
ll dp[maxn][3];

int main()
{
    int n, l, r;
    cin >> n >> l >> r;
    int mod0, mod1, mod2;
    l--;
    mod0 = r / 3;
    mod0 -= l / 3;
    mod1 = r / 3 + (r % 3 >= 1) - l / 3 - (l % 3 >= 1);
    mod2 = r / 3 + (r % 3 >= 2) - l / 3 - (l % 3 >= 2);
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 3; j++){
            dp[i][j] = dp[i - 1][j] * mod0;
            dp[i][j] %= mod;
            dp[i][j] += dp[i - 1][((j - 1) + 3) % 3] * mod1;
            dp[i][j] %= mod;
            dp[i][j] += dp[i - 1][((j - 2) + 3) % 3] * mod2;
            dp[i][j] %= mod;
        }
    }
    cout << dp[n][0];
    return 0;
}
