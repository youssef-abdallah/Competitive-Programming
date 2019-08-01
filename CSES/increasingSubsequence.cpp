#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> ans;
    int len = 0;
    for (int i = 0; i < n; i++){
        int idx = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
        if (idx == len){
            ans.push_back(a[i]);
            len++;
        } else {
            ans[idx] = a[i];
        }
    }
    cout << len;
    return 0;
}
