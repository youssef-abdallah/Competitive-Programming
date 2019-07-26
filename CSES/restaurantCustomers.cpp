#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    set<pair<int, int>> st;
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        st.insert({a, 1});
        st.insert({b, -1});
    }
    int cur = 0;
    int best = 0;
    for (auto &elem : st){
        cur += elem.second;
        best = max(cur, best);
    }
    cout << best;
    return 0;
}
