#include <bits/stdc++.h>

using namespace std;

int dp[110][110];
int a[110], b[110];

int main()
{
    int n, m;
    vector<int> ans;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> b[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if (a[i] == b[j] && 1 + dp[i - 1][j - 1] > dp[i][j]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int i = n, j = m;
    while(i && j){
        if(a[i] == b[j]){
            ans.push_back(a[i]);
            i--;
            j--;
        } else if(dp[i - 1][j] > dp[i][j -1]){
            i--;
        } else{
            j--;
        }
    }
    for(int i = ans.size() - 1; i >= 0; i--){
        cout << ans[i] << " ";
    }
    return 0;
}
