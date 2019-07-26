
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    int lo = 1, hi = n;
    while(lo < hi){
        ll sum = ll(a[lo].first) + ll(a[hi].first);
        if (sum == x){
            cout << a[lo].second << " " << a[hi].second;
            return 0;
        } else if (sum < x){
            lo++;
        } else {
            hi--;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
