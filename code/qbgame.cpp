#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 10004;
int s[256], a[8][N];
LL f[N][256];
vector<int> states;

int main() {
    int n, mx = numeric_limits<int>::min();
    scanf("%d", &n);
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
            mx = max(mx, a[i][j]);
        }
    }
    if(mx < 0) {
        printf("%d", mx);
        return 0;
    }
    for(int t = 0; t < 256; ++t) {
        if(t & (t >> 1)) {
            continue;
        }
        states.push_back(t);
    }
    memset(f, 0xff, sizeof(f));
    f[0][0] = 0;
    for(int i = 0; i < n; ++i) {
        s[0] = 0;
        for(int j = 0; j < 8; ++j) {
            s[1 << j] = a[j][i];
        }
        for(int t = 1, w; t < 256; ++t) {
            if(w = t & (t - 1)) {
                s[t] = s[w] + s[t ^ w];
            }
        }
        for(int j : states) {
            LL ft = f[i][j];
            if(ft == -1) continue;
            for(int t : states) {
                if((t & (t >> 1)) || (j & t)) continue;
                f[i + 1][t] = max(f[i + 1][t], ft + s[t]);
            }
        }
    }
    LL res = 0;
    for(int t : states) {
        res = max(res, f[n][t]);
    }
    printf("%lld", res);
    return 0;
}
