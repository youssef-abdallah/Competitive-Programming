#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxn = 2e5 + 10;
const ll Inf = 1e18;

int n;
int a[maxn];

ll f(int mid){
    ll ans = 0;
    for (int i = 0; i < n; i++){
        ans += abs(a[i] - mid);
    }
    return ans;
}



int main()
{
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int left = 1, right = 1e9;
    for(int i=0; i<100; i++){
		ll g = left + (right - left) / 3, h = left + 2 * (right - left) / 3;
		if (f(g) < f(h)) // use > if f increase then decrease
			right = h;
		else
			left = g;
	}
	ll cost = Inf;
	while(left <= right){
       cost = min(cost, f(left++));
	}
	cout << cost;
    return 0;
}
