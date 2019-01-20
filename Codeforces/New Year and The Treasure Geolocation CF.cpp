#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n, a, b;
    long long suma = 0, sumb = 0;
    cin >> n;
    for(int i = 0; i < 2 * n; i++){
        cin >> a >> b;
        suma += a;
        sumb += b;
    }
    cout << suma / n << " " << sumb / n;
    return 0;
}
