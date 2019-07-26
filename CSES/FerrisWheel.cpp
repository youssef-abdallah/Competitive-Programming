#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    multiset<int> st;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        st.insert(a);
    }
    int ans = 0;
    while(!st.empty()){
        auto it = --st.upper_bound(x - *st.begin());
        if (it != st.end() && (*it + *st.begin() <= x) && it != st.begin()){
            st.erase(it);
            st.erase(st.begin());
            ans++;
        } else {
            st.erase(st.begin());
            ans++;
        }
    }
    cout << ans;
    return 0;
}
