#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100010];
int ans = 0;

bool dfs(int v, int p){
    int colored = 0;
    for(auto u : adj[v]){
        if (u != p) {
            colored |= dfs(u, v);
        }
    }
    ans += colored;
    return !colored;
}

int main()
{
    int n, a, b;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, -1);
    cout << ans;
    return 0;
}
