#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long LL;

const int N = 102;
int cnt[8] = { 0, 1, 1, 2, 1, 2, 2, 3 };
int n, a[N], f[N][8][8];
LL c[N][8][8];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        --a[i];
    }
    memset(f, 0xff, sizeof(f));
    f[0][0][0] = 0;
    c[0][0][0] = 1;
    for(int i = 0; i < n; ++i) {
        for(int t1 = 0; t1 < 8; ++t1) {
            for(int t2 = 0; t2 < 8; ++t2) {
                int ff = f[i][t1][t2];
                LL cc = c[i][t1][t2];
                if(ff == -1) continue;
                for(int t = 0; t < 8; ++t) {
                    if((~a[i]) && (t >> a[i] & 1)) continue;
                    if((t1 & (t >> 1)) || (t1 & (t << 1)) || (t2 & (t >> 2)) || (t2 & (t << 2))) continue;
                    if(f[i + 1][t2][t] < ff + cnt[t]) {
                        f[i + 1][t2][t] = ff + cnt[t];
                        c[i + 1][t2][t] = cc;
                    }
                    else if(f[i + 1][t2][t] == ff + cnt[t]) {
                        c[i + 1][t2][t] += cc;
                    }
                }
            }
        }
    }
    int M = 0;
    LL L = 1;
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            if(M < f[n][i][j]) {
                M = f[n][i][j];
                L = c[n][i][j];
            }
            else if(M == f[n][i][j]) {
                L += c[n][i][j];
            }
        }
    }
    printf("%d %llu", M, L);
    return 0;
}
