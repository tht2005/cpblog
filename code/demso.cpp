#include <bits/stdc++.h>

using namespace std;

#define LL long long

#define N 17

int n, a[N];
LL d, kk, f[N][N][10];

LL calc(LL val) {
    n = 0;
    do {
        a[n++] = val % 10;
    } while(val /= 10);
    LL res = 0;
    for(int i = 1; i < n; ++i) {
        for(int j = 1; j < 10; ++j) {
            res += f[i][kk][j];
        }
    }
    for(int i = n, cnt = 0; i--; ) {
        for(int j = (i + 1 == n); j < a[i]; ++j) {
            int k = cnt + (i + 1 < n && abs(a[i + 1] - j) <= d);
            if(k <= kk) {
                res += f[i + 1][kk - k][j];
            }
        }
        if(i + 1 < n && abs(a[i] - a[i + 1]) <= d) {
            ++cnt;
        }
    }
    return res;
}

int main() {
    LL a, b;
    scanf("%lld %lld %lld %lld", &a, &b, &d, &kk);
    memset(f, 0, sizeof(f));
    for(int i = 0; i < 10; ++i) {
        f[1][0][i] = 1;
    }
    for(int i = 2; i < N; ++i) {
        for(int j = 0; j < i; ++j) {
            for(int k = 0; k < 10; ++k) {
                for(int t = 0; t < 10; ++t) {
                    if(abs(k - t) > d) {
                        f[i][j][k] += f[i - 1][j][t];
                    }
                    else if(j) {
                        f[i][j][k] += f[i - 1][j - 1][t];
                    }
                }
            }
        }
    }
    for(int i = 1; i < N; ++i) {
        for(int j = 1; j < N; ++j) {
            for(int k = 0; k < 10; ++k) {
                f[i][j][k] += f[i][j - 1][k];
            }
        }
    }
    printf("%lld", calc(b + 1) - calc(a));
    return 0;
}
