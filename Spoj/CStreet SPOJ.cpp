#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> adj[10010];
bool taken[100010];

int main()
{
    int n, e, x, y, w, t, p;
    cin >> t;
    while(t--){
        cin >> p >> n >> e;
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < e; i++){
            cin >> x >> y >> w;
            adj[x].push_back({-w, -y});
            adj[y].push_back({-w, -x});
        }
        int cost = 0;
        taken[1] = 1;
        for(auto elem : adj[1]){
            pq.push(elem);
        }
        while(!pq.empty()){
            pair<int, int> u = pq.top();
            pq.pop();
            if (!taken[-u.second]){
                cost += -u.first;
                taken[-u.second] = 1;
                for(auto elem : adj[-u.second]){
                    pq.push(elem);
                }
            }
        }
        cout << cost * p << endl;
    }
    return 0;
}
