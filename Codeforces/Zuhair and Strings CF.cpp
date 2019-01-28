#include <bits/stdc++.h>

using namespace std;
int freq[26];

int main()
{
    int k, n;
    string s;
    cin >> n >> k;
    cin >> s;
    int p1 = 0, p2;
    int ans = 0;
    while(p1 < n){
        p2 = p1 + 1;
        while(p2 < n && s[p1] == s[p2]){
            p2++;
        }
        freq[s[p1] - 'a'] += (p2 - p1) / k;
        p1 = p2;
    }
    for(int i = 0; i < 26; i++){
        ans = max(ans, freq[i]);
    }
    cout << ans;
    return 0;
}
