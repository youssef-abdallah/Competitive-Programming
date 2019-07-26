#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 5;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> dp(x + 1, INF), c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    dp[0] = 0;
    for (int i = 1; i <= x; i++){
        for (int j = 0; j < n; j++){
            if (i - c[j] >= 0)
                dp[i] = min(1 + dp[i - c[j]], dp[i]);
        }
    }
    if (dp[x] == INF) cout << "-1";
    else cout << dp[x];
    return 0;
}
