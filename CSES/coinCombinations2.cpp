#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int mod = 1e9 + 7;
int dp[101][1000001];
const int maxn = 110;
int c[maxn];

int main()
{
    int n, x;
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; i++){
        scanf("%d", &c[i]);
    }
    for (int i = 0; i < n; i++) dp[i][0] = 1;
    for (int i = 0; i < n; i++){
        for (int j = 1; j <= x; j++){
            if (j - c[i] >= 0){
                dp[i][j] = (ll(dp[i][j]) + ll(dp[i][j - c[i]])) % mod;
            }
            if (i > 0){
                dp[i][j] = (ll(dp[i][j]) + ll(dp[i - 1][j])) % mod;
            }
        }
    }
    printf("%d", dp[n - 1][x]);
    return 0;
}
