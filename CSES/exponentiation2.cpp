#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;
const ll Inf = 1e18 + 5;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1LL;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    while(n--){
        ll a, b, c;
        cin >> a >> b >> c;
        ll temp = binpow(b, c, mod - 1);
        cout << binpow(a, temp, mod) << endl;
    }
    return 0;
}
