#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 110;
ll v[maxn], w[maxn];
ll dp[maxn][100011];

const ll INF = 1e18;

int main()
{
    int n, W;
    cin >> n >> W;
    for(int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= 100010; j++){
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for(int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 100010; j++){
            if (j >= v[i]){
                dp[i][j] = min(dp[i - 1][j - v[i]] + w[i], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    int best = -1;
    for(int i = 0; i <= 100010; i++){
        if (dp[n][i] <= W){
            best = max(best, i);
        }
    }
    cout << best;
    return 0;
}
