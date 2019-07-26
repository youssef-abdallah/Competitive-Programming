#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    multiset<int> st;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        st.insert(a[i]);
    }
    for (int i = 0; i < m; i++){
        cin >> b[i];
        auto it = st.size() > 0 ? --st.upper_bound(b[i]) : st.end();
        if (it != st.end()){
            cout << *it << endl;
            st.erase(it);
        } else {
            cout << "-1" << endl;
        }
    }
    return 0;
}
