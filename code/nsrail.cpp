#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 502;
int a[N][N];
LL c[N][N], f[N], g[N];

int main() {
    int n, kk;
    scanf("%d %d", &n, &kk);
    if(kk == 0) {
        putchar('0');
        return 0;
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = i + 1; j <= n; ++j) {
            a[i][j] += a[j][i] + a[i][j - 1];
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            c[i][j] = 0;
            for(int k = j; k > i; --k) {
                c[i][j] += a[k][n] - a[k][j];
            }
        }
    }
    for(int i = 1; i < n; ++i) {
        f[i] = c[0][i];
    }
    for(int t = 1; t < kk; ++t) {
        for(int i = 1; i < n; ++i) {
            g[i] = f[i];
            f[i] = -1;
        }
        for(int i = 1; i < n; ++i) {
            LL ft = g[i];
            if(ft == -1) continue;
            for(int j = i + 1; j < n; ++j) {
                f[j] = max(f[j], ft + c[i][j]);
            }
        }
    }
    LL res = 0;
    for(int i = 1; i < n; ++i) {
        res = max(res, f[i]);
    }
    printf("%lld", res);
    return 0;
}
