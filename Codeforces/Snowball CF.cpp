#include <bits/stdc++.h>
using namespace std;

int main()
{
    int w, h, u1, d1, u2, d2;
    cin >> w >> h >> u1 >> d1 >> u2 >> d2;
    for(int i = h; i > 0; i--){
        w += i;
        if (i == d1){
            w = max(0, w - u1);
            continue;
        } else if (i == d2){
            w = max(0, w - u2);
            continue;
        }
    }
    cout << w;
    return 0;
}
