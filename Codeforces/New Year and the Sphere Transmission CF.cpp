#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<ll> divisors;
set<ll> ans;

ll lcm(ll a, ll b){
    return a / __gcd(a, b) * b;
}


int main()
{
    ll n;
    cin >> n;
    ans.insert(1);
    for(ll i = 2; i * i <= n; i++){
        if (n % i == 0){
            divisors.push_back(i);
            if (i * i != n){
                divisors.push_back(n / i);
            }
        }
    }
    ans.insert(n * (2 + n - 1) / 2);
    for(ll elem : divisors){
        ll tmp = lcm(n, elem) / elem;
        ans.insert(elem * (2 + tmp * (elem - 1)) / 2);
    }
    for(auto elem : ans){
        cout << elem << " ";
    }
    return 0;
}
