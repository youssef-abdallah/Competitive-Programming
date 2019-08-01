#include <bits/stdc++.h>

using namespace std;

const int Inf = 1e9 + 5;

int dp[505][505];

int solve(int a, int b){
    if (a == b) return 0;
    if (dp[a][b] != -1) return dp[a][b];
    int res = Inf;
    for (int i = 1; i < a; i++){
        res = min(res, 1 + solve(b, i) + solve(b, a - i));
    }
    for (int i = 1; i < b; i++){
        res = min(res, 1 + solve(a, i) + solve(a, b - i));
    }
    return dp[a][b] = res;
}

int main()
{
    int a, b;
    memset(dp, -1, sizeof(dp));
    cin >> a >> b;
    cout << solve(a, b);
    return 0;
}
