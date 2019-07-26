#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    while(n--){
        ll a, b;
        cin >> a >> b;
        cout << binpow(a, b, mod) << endl;
    }
    return 0;
}
