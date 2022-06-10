#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
LL f[1000002];
int g[1000002];

int main() {
    char c = getchar();
    while(c < '0' || c > '9') {
        c = getchar();
    }
    int cnt = 0;
    for(; '0' <= c && c <= '9'; c = getchar()) {
        if(c == '7') {
            ++cnt;
        }
        else if(cnt) {
            f[1] += cnt + 1;
            f[cnt + 1] -= cnt + 1;
            ++g[1];
            --g[cnt + 1];
            cnt = 0;
        }
    }
    if(cnt) {
        f[1] += cnt + 1;
        f[cnt + 1] -= cnt + 1;
        ++g[1];
        --g[cnt + 1];
    }
    int i = 0;
    LL val;
    while(++i, val = (f[i] += f[i - 1]) - (LL)i * (g[i] += g[i - 1])) {
        printf("%d %lld\n", i, val);
    }
    return 0;
}
