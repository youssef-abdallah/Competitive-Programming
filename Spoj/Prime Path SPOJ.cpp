#include <bits/stdc++.h>

using namespace std;

vector<int> primes;
vector<int> adj[100010];

bool cmp(int x, int y){
    int diff = 0;
    if (x % 10 != y % 10) diff++;
    x /= 10, y /= 10;
    if (x % 10 != y % 10) diff++;
    x /= 10, y /= 10;
    if (x % 10 != y % 10) diff++;
    x /= 10, y /= 10;
    if (x % 10 != y % 10) diff++;
    return diff == 1;
}

int main()
{
    int t, src, dest;
    cin >> t;
    for(int i = 1001; i <= 9999; i++){
        bool prime = true;
        for(int j = 2; j * j <= i; j++){
            if (i % j == 0){
                prime = false;
                break;
            }
        }
        if (prime)
            primes.push_back(i);
    }
    int len = primes.size();
    for(int i = 0; i < len; i++){
        for(int j = i + 1; j < len; j++){
            if (cmp(primes[i], primes[j])){
                adj[primes[i]].push_back(primes[j]);
                adj[primes[j]].push_back(primes[i]);
            }
        }
    }
    while(t--){
        cin >> src >> dest;
        queue<int> q;
        vector<bool> visited(100000);
        vector<int> d(100000);
        q.push(src);
        visited[src] = 1;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto elem : adj[u]){
                if (!visited[elem]){
                    visited[elem] = 1;
                    q.push(elem);
                    d[elem] = 1 + d[u];
                }
            }
        }
        cout << d[dest] << endl;
    }
    return 0;
}
