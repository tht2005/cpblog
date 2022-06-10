#include <bits/stdc++.h>

using namespace std;

const int N = 10004;
int s[16], a[4][N], f[N][16];

int main() {
    int n, mx = numeric_limits<int>::min();
    scanf("%d", &n);
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
            mx = max(mx, a[i][j]);
        }
    }
    if(mx < 0) {
        printf("%d", mx);
        return 0;
    }
    memset(f, 0xff, sizeof(f));
    f[0][0] = 0;
    for(int i = 0; i < n; ++i) {
        s[0] = 0;
        for(int j = 0; j < 4; ++j) {
            s[1 << j] = a[j][i];
        }
        for(int t = 1, w; t < 16; ++t) {
            if(w = t & (t - 1)) {
                s[t] = s[w] + s[t ^ w];
            }
        }
        for(int j = 0; j < 16; ++j) {
            int ft = f[i][j];
            if(ft == -1) continue;
            for(int t = 0; t < 16; ++t) {
                if((t & (t >> 1)) || (j & t)) continue;
                f[i + 1][t] = max(f[i + 1][t], ft + s[t]);
            }
        }
    }
    int res = 0;
    for(int t = 0; t < 16; ++t) {
        res = max(res, f[n][t]);
    }
    printf("%d", res);
    return 0;
}
