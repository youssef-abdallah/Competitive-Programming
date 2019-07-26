#include <bits/stdc++.h>

using namespace std;

int getMaxDigit(int n){
    int maxi = 0;
    while(n){
        maxi = max(maxi, n % 10);
        n /= 10;
    }
    return maxi;
}

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    while(n > 0){
        ans++;
        n -= getMaxDigit(n);
    }
    cout << ans;
    return 0;
}
