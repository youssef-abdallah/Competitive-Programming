#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int freq[1000010];
int _sievesize;

vector<int> divisors[1000010];

void sieve(int upperbound){
    _sievesize = upperbound + 1;
    for (ll i = 1; i * i <= _sievesize; i++){
        for (ll j = i * i; j <= _sievesize; j += i){
            divisors[j].push_back(i);
        }
    }
}

int main()
{
    sieve(1e6 + 2);
    int n;
    scanf("%d", &n);
    int best = 1;
    for (int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        for (auto div : divisors[x]){
            freq[div]++;
            if(freq[div] >= 2 && div > best){
                best = div;
            }
            if (x / div != div) {
                freq[x / div]++;
                if(freq[x / div] >= 2 && x / div > best){
                    best = x / div;
                }
            }
        }
    }
    printf("%d", best);
    return 0;
}
