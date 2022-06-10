#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long LL;

const int N = 11;

int n;
LL res[N], f[N][N], nCr[N][N];

int main() {
    for(int i = 0; i < N; ++i) {
        nCr[i][0] = nCr[i][i] = 1;
        for(int j = 1, k = i >> 1; j <= k; ++j) {
            nCr[i][j] = nCr[i][i - j] = nCr[i - 1][j] + nCr[i - 1][j - 1];
        }
    }
    f[0][0] = 1;
    for(int i = 1; i < N; ++i) {
        for(int j = 1; j <= i; ++j) {
            for(int k = i; k >= j; --k) {
                f[i][j] += f[k - 1][j - 1] * nCr[i][i - k + 1];
            }
            res[i] += f[i][j];
        }
    }
    while(scanf("%d", &n), n != -1) {
        printf("%llu\n", res[n]);
    }
    return 0;
}
