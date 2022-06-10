#include <bits/stdc++.h>

using namespace std;

const int N = 10;
const int md = (int)1e9 + 7;

int n;

void matmul(int a[N][N], int b[N][N], int r[N][N]) {
    static int c[N][N];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            long long s = 0;
            for(int k = 0; k < n; ++k) {
                s += (long long)a[i][k] * b[k][j] % md;
            }
            c[i][j] = s % md;
        }
    }
    memcpy(r, c, sizeof(c));
}
void matpow(int a[N][N], int e, int r[N][N]) {
    static int c[N][N];
    memset(c, 0, sizeof(c));
    for(int i = 0; i < n; ++i) {
        c[i][i] = 1;
    }
    for(; e > 0; e >>= 1) {
        if(e & 1) matmul(c, a, c);
        matmul(a, a, a);
    }
    memcpy(r, c, sizeof(c));
}

int q, k, a[N][N], b[N][N];

int main() {
    scanf("%d %d", &n, &q);
    while(q--) {
        a[0][0] = 1;
        for(int i = 1; i < n; ++i) {
            a[0][i] = 0;
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                b[i][j] = 0;
            }
        }
        for(int i = 0; i < n; ++i) {
            if(i) b[i - 1][i] = 1;
            if(i + 1 < n) b[i + 1][i] = 1;
        }
        scanf("%d", &k);
        matpow(b, k, b);
        matmul(a, b, a);
        printf("%d\n", a[0][n - 1]);
    }
    return 0;
}
