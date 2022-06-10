#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long LL;

const int N = 11;

int n;
long long k;
LL f[N][N * (N - 1) / 2], nCr[N][N];

int main() {
    for(int i = 0; i < N; ++i) {
        nCr[i][0] = nCr[i][i] = 1;
        for(int j = 1, k = i >> 1; j <= k; ++j) {
            nCr[i][j] = nCr[i][i - j] = nCr[i - 1][j] + nCr[i - 1][j - 1];
        }
    }
    f[0][0] = 1;
    for(int i = 1, L = 0; i < N; L += i, ++i) {
        for(int j = 0; j <= L; ++j) {
            for(int k = i; k > 0 && j >= (i - k + 1) * (i - k) / 2; --k) {
                f[i][j] += f[k - 1][j - (i - k + 1) * (i - k) / 2] * nCr[i][i - k + 1];
            }
        }
    }
    while(scanf("%d", &n), n != -1) {
        scanf("%lld", &k);
        printf("%llu\n", (k < 0 || k > n * (n - 1) / 2) ? 0 : f[n][k]);
    }
    return 0;
}
