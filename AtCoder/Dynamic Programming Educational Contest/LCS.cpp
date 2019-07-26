    #include <bits/stdc++.h>

    using namespace std;

    const int maxn = 3005;

    int dp[maxn][maxn];
    pair<int, int> par[maxn][maxn];
    int main()
    {
        string s1, s2;
        cin >> s1 >> s2;
        int n1 = s1.length();
        int n2 = s2.length();
        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                if (s1[i - 1] == s2[j - 1]){
                    if (1 + dp[i - 1][j - 1] > dp[i][j]){
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                        par[i][j] = {i - 1, j - 1};
                    }
                } else {
                    if (dp[i - 1][j] > dp[i][j - 1]){
                        dp[i][j] = dp[i - 1][j];
                        par[i][j] = {i - 1, j};
                    } else {
                        dp[i][j] = dp[i][j - 1];
                        par[i][j] = {i, j - 1};
                    }
                }
            }
        }
        for(int i = 0; i <= n1; i++){
            par[i][0] = {-1, -1};
        }
        for(int j = 0; j <= n2; j++){
            par[0][j] = {-1, -1};
        }
        int i = n1;
        int j = n2;
        vector<char> ans;
        while(par[i][j].first != -1 && par[i][j].second != -1){
            pair<int, int> tmp = par[i][j];
            if (s1[i - 1] == s2[j - 1]){
                ans.push_back(s1[i - 1]);
            }
            i = tmp.first;
            j = tmp.second;
        }
        reverse(ans.begin(), ans.end());
        for(auto ch : ans){
            cout << ch;
        }
        return 0;
    }
