#include <bits/stdc++.h>

using namespace std;
bool cmp(pair<int, int> &a, pair<int, int> &b){
    if (a.first != b.first) return a.first < b.first;
    return a.first < b.first;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++){
        int bgn, finish;
        cin >> bgn >> finish;
        v[i].first = finish;
        v[i].second = bgn;
    }
    sort(v.begin(), v.end(), cmp);
    int ans = 0;
    int lst = -1;
    for (int i = 0; i < n; i++){
        if (v[i].second < lst){
            continue;
        } else {
            ans++;
            lst = v[i].first;
        }
    }
    cout << ans;
    return 0;
}
