#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll _sieve_size;
bitset<10000010> bs;
vector<ll> primes;

// first part

void sieve(ll upperbound) {
  _sieve_size = upperbound + 1;
  bs.set();
  bs[0] = bs[1] = 0;
  for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
    for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
    primes.push_back((i));
} }

bool isPrime(ll N) {
  if (N <= _sieve_size) return bs[N];
  for (int i = 0; i < (int)primes.size(); i++)
    if (N % primes[i] == 0) return false;
  return true;
}


int main()
{
    ll n;
    cin >> n;
    sieve(1e6 + 5);
    while(n--){
        ll x, cnt = 0;
        ll ans = 1;
        cin >> x;
        for (auto p : primes){
            cnt = 1;
            while(x % p == 0){
                cnt++;
                x /= p;
            }
            ans = ans * cnt;
            if (p * p >= x){
                ans *= (1 + (x > 1));
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
