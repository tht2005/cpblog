#include <bits/stdc++.h>

using namespace std;

int n, i, cnt;
string s, t;
long long res;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    getline(cin, s);
    getline(cin, t);
    cnt = 0;
    res = 0;
    n = s.size();
    for(i = 0; i < n; ++i) {
        if(s[i] == t[1]) {
            res += cnt;
        }
        if(s[i] == t[0]) {
            ++cnt;
        }
    }
    cout << res;
    return 0;
}
