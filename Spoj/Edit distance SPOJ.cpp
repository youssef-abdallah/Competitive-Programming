#include <bits/stdc++.h>

using namespace std;

int dp[2010][2010];

int main()
{
    string a, b;
    int t;
    cin >> t;
    while(t--){
        cin >> a >> b;
        int n = a.length();
        int m = b.length();
        for(int i = 0; i <= m; i++){
            dp[0][i] = i;
        }
        for(int i = 0; i <= n; i++){
            dp[i][0] = i;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int c = a[i - 1] != b[j - 1];
                dp[i][j] = min(dp[i - 1][j - 1] + c, 1 + dp[i - 1][j]);
                dp[i][j] = min(dp[i][j], 1 + dp[i][j - 1]);
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}
