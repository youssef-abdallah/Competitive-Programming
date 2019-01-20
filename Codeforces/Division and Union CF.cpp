#include <bits/stdc++.h>

using namespace std;
vector<pair<pair<int, int> , int>> vec;

bool cmp(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b){
    if (a.first.first != b.first.first){
        return a.first.first < b.first.first;
    }
    if (a.first.second != b.first.second){
        return a.first.second < b.first.second;
    }
    return a.second < b.second;
}

int main()
{
    int t, n, l, r;
    cin >> t;
    while(t--){
        bool possible = false;
        map<int, int> ans;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> l >> r;
            vec.push_back({{l, r}, i});
        }
        sort(vec.begin(), vec.end(), cmp);
        int tmp;
        tmp = vec[0].first.second;
        ans[vec[0].second] = 1;
        for(int i = 1; i < n; i++){
            if (vec[i].first.first > tmp){
                possible = true;
               ans[vec[i].second] = 2;
            } else {
                ans[vec[i].second] = 1;
                tmp = max(tmp, vec[i].first.second);
            }
        }
        if (!possible){
            cout << "-1" << endl;
        } else {
            for(int i = 0; i < n; i++){
                cout << ans[i] << " ";
            }
            cout << endl;
        }
        vec.clear();
        ans.clear();
    }
    return 0;
}
