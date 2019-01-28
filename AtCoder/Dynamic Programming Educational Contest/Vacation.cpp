#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
int a[maxn], b[maxn], c[maxn];
int dp[maxn][3];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i] >> c[i];
    }
    dp[1][0] = a[0];
    dp[1][1] = b[0];
    dp[1][2] = c[0];
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < 3; j++){
            if (j == 0){
                dp[i][j] = a[i - 1] + max(dp[i - 1][1], dp[i - 1][2]);
            } else if (j == 1){
                dp[i][j] = b[i - 1] + max(dp[i - 1][0], dp[i - 1][2]);
            } else {
                dp[i][j] = c[i - 1] + max(dp[i - 1][1], dp[i - 1][0]);
            }
        }
    }
    int maxi = -1;
    for(int i = 0; i < 3; i++){
        maxi = max(maxi, dp[n][i]);
    }
    cout << maxi;
    return 0;
}
