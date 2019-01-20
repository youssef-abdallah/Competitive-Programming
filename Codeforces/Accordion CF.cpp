#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    string s;
    cin >> s;
    int len = s.length();
    int c = 0;
    int maxi = 0;
    int cnt = 0;
    bool proceed = false;
    for(int i = len - 1; i >= 0; i--){
        if (!proceed && s[i] == ']'){
            proceed = true;
        }
        if (proceed && s[i] == ':'){
            cnt++;
        }
    }
    if (!proceed || cnt < 2){
        cout << "-1";
        return 0;
    }
    for(int i = 0; i < len; i++){
        if (s[i] == ':'){
            cnt--;
        }
        if (c == 0){
            if (s[i] == '['){
                maxi++;
                c++;
            }
        } else if (c == 1){
            if (s[i] == ':'){
                maxi++;
                c++;
            }
        }
        else if (c == 2){
            if (s[i] != ':'){
                if (s[i] == '|'){
                    maxi++;
                }
            }
            else if (cnt == 0) {
                maxi++;
                c++;
            }
        }
        else if (c == 3){
            if (s[i] == ']'){
                maxi++;
                c++;
                break;
            }
        }
    }
    if (c == 4){
        cout << maxi;
    } else {
        cout << "-1";
    }
    return 0;
}
