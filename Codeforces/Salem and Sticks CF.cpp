#include <bits/stdc++.h>

using namespace std;
int a[1010];
int n;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int ans = 10000000;
    int t;
    for(int i = 1; i <= 100; i++){
        int cost = 0;
        for(int j = 0; j < n; j++){
            if (abs(a[j] - i) > 1){
                cost += abs(abs(a[j] - i) - 1);
            }
        }
        if (cost < ans){
            t = i;
        }
        ans = min(ans, cost);
    }
    cout << t << " " << ans;
    return 0;
}
