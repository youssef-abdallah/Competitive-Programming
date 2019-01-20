#include <bits/stdc++.h>

using namespace std;

char g[35][35][35];
bool visited[35][35][35];
int d[35][35][35];
int dl[6] = {0, 0, 0, 0, 1, -1};
int dr[6] = {0, 0, 1, -1, 0, 0};
int dc[6] = {1, -1, 0, 0, 0, 0};

typedef pair<pair<int, int>, int> ppi;
int l, r, c;
queue<ppi> q;

bool isValid(int x, int y, int z){
    if (x < 0 || y < 0 || z < 0)
        return false;
    if (x >= l || y >= r || z >= c)
        return false;
    if (g[x][y][z] == '#')
        return false;
    return true;
}

int main()
{
    ppi start, endd;
    while(cin >> l >> r >> c && (l || r || c)){
        for(int i = 0; i < l; i++){
            for(int j = 0; j < r; j++){
                for(int k = 0; k < c; k++){
                    cin >> g[i][j][k];
                    if (g[i][j][k] == 'S'){
                        start = {{i, j}, k};
                    } else if (g[i][j][k] == 'E'){
                        endd = {{i, j}, k};
                    }
                }
            }
        }
        q.push(start);
        visited[start.first.first][start.first.second][start.second] = 1;
        while(!q.empty()){
            ppi u = q.front();
            q.pop();
            for(int i = 0; i < 6; i++){
                if (isValid(u.first.first + dl[i], u.first.second + dr[i], u.second + dc[i])
                     && !visited[u.first.first + dl[i]][u.first.second + dr[i]][u.second + dc[i]]){
                        q.push({{u.first.first + dl[i], u.first.second + dr[i]}, u.second + dc[i]});
                        visited[u.first.first + dl[i]][u.first.second + dr[i]][u.second + dc[i]] = 1;
                        d[u.first.first + dl[i]][u.first.second + dr[i]][u.second + dc[i]] = 1 + d[u.first.first][u.first.second][u.second];
                     }
            }
        }
        if (d[endd.first.first][endd.first.second][endd.second] != 0)
            cout << "Escaped in " << d[endd.first.first][endd.first.second][endd.second] << " minute(s)."  << endl;
        else {
            cout << "Trapped!" << endl;
        }
        memset(visited, 0, sizeof visited);
        memset(d, 0, sizeof d);
    }
    return 0;
}
