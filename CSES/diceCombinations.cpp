#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 0; i <= n; i++){
        for (int j = 1; j <= 6; j++){
            if (i + j <= n){
                dp[i + j] = (dp[i] + dp[i + j]) % mod;
            }
        }
    }
    cout << dp[n];
    return 0;
}
