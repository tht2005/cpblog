#include <bits/stdc++.h>

using namespace std;

const int md = 76213;
int add(int a, int b) { a += b; if(a >= md) a -= md; return a; }
#define mul(a, b) ((long long)(a) * (b) % md)

const int N = 5003;
int f[N], nCr[N][N];

int main() {
    int n;
    scanf("%d", &n);
    f[0] = 1;
    for(int i = 1; i <= n; ++i) {
        f[i] = mul(f[i - 1], i);
    }
    for(int i = 0; i <= n; ++i) {
        nCr[i][0] = nCr[i][i] = 1;
        for(int j = 1, k = i >> 1; j <= k; ++j) {
            nCr[i][j] = nCr[i][i - j] = add(nCr[i - 1][j], nCr[i - 1][j - 1]);
        }
    }
    int res = 0;
    for(int i = 0; i <= n; ++i) {
        if(i & 1) {
            res -= mul(nCr[n][i], f[n - i]);
        }
        else {
            res += mul(nCr[n][i], f[n - i]);
        }
    }
    res %= md;
    if(res < 0) res += md;
    printf("%d", res);
    return 0;
}
