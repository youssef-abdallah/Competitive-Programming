#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

int dp[maxn], a[maxn];
const int INF = 1e9;

int main()
{
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        dp[i] = INF;
    }
    dp[2] = abs(a[2] - a[1]);
    dp[1] = 0;
    for(int i = 3; i <= n; i++){
        for(int j = 1; j <= k && j < i; j++){
            dp[i] = min(dp[i], dp[i - j] +  abs(a[i] - a[i - j]));
        }
    }
    cout << dp[n];
    return 0;
}
