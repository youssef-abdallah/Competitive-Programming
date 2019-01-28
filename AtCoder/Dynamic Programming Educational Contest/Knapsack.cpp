#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 110;
ll v[maxn], w[maxn];
ll dp[maxn][100010];

int main()
{
    int n, W;
    cin >> n >> W;
    for(int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }
    for(int i = 0; i <= W; i++)
        dp[0][i] = 0;
    for(int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= W; j++){
            if (j >= w[i]){
                dp[i][j] = max(dp[i - 1][j - w[i]] + v[i], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][W];
    return 0;
}
