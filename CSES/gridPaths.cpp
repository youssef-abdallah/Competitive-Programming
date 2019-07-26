#include <bits/stdc++.h>

using namespace std;

int dp[1010][1010];
char g[1010][1010];

const int mod = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        scanf("%s", g[i] + 1);
    }
    dp[1][1] = (g[1][1] == '.');
    for (int i = 2; i <= n; i++) dp[i][1] = g[i][1] != '*' ? dp[i - 1][1] : 0;
    for (int i = 2; i <= n; i++) dp[1][i] = g[1][i] != '*' ? dp[1][i - 1] : 0;
    for (int i= 2; i <= n; i++){
        for (int j = 2; j <= n; j++){
            if (g[i][j] != '*'){
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
                dp[i][j] =  (dp[i][j - 1] + dp[i][j] ) % mod;
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    printf("%d", dp[n][n]);
    return 0;
}

