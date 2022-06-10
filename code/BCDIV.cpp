#include <bits/stdc++.h>

using namespace std;

const int N = 26;
long long nCr[N][N], f[N][N];

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
            for(int k = 1; k <= i; ++k) {
                f[i][j] += f[i - k][j - 1] * nCr[i - 1][k - 1];
            }
        }
    }
    int q;
    scanf("%d", &q);
    while(q--) {
        int n, k;
        scanf("%d %d", &n, &k);
        printf("%lld\n", f[n][k]);
    }
    return 0;
}
