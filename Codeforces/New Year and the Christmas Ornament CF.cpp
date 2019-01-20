#include <bits/stdc++.h>

using namespace std;

int main()
{
    int y, b, r;
    int ans = 0;
    cin >> y >> b >> r;
    for(int i = 1; i <= y; i++){
        if (i + 1 <= b && i + 2 <= r){
            ans = max(ans, 3 * (i + 1));
        }
    }
    cout << ans;
    return 0;
}
