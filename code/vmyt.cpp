#include <bits/stdc++.h>

using namespace std;

const int md = (int)1e9 + 7;
const int phi_md = md - 1;

const int N = 55;
int K;

void matrix_mul(int a[N][N], int b[N][N], int res[N][N]) {
    static int c[N][N];
    for(int i = 0; i < K; ++i) {
        for(int j = 0; j < K; ++j) {
            c[i][j] = 0;
            for(int k = 0; k < K; ++k) {
                c[i][j] = (c[i][j] + (long long)a[i][k] * b[k][j]) % phi_md;
            }
        }
    }
    for(int i = 0; i < K; ++i) {
        for(int j = 0; j < K; ++j) {
            res[i][j] = c[i][j];
        }
    }
}
void matrix_pow(int a[N][N], int n, int res[N][N]) {
    static int c[N][N];
    for(int i = 0; i < K; ++i) {
        for(int j = 0; j < K; ++j) {
            c[i][j] = (i == j);
        }
    }
    for(; n > 0; n >>= 1) {
        if(n & 1) matrix_mul(c, a, c);
        matrix_mul(a, a, a);
    }
    for(int i = 0; i < K; ++i) {
        for(int j = 0; j < K; ++j) {
            res[i][j] = c[i][j];
        }
    }
}

int binpow(int a, int n) {
    int res = 1;
    for(; n > 0; n >>= 1) {
        if(n & 1) res = (long long)res * a % md;
        a = (long long)a * a % md;
    }
    return res;
}

int main() {
    int n, a[N];
    scanf("%d %d", &n, &K);
    for(int i = 0; i < K; ++i) {
        scanf("%d", a + i);
    }
    int l[N][N], r[N][N];
    for(int i = 0; i < K; ++i) {
        memset(l[i], 0, sizeof(l[i]));
        l[i][i] = 1;
        memset(r[i], 0, sizeof(r[i]));
        if(i) r[i][i - 1] = 1;
        r[i][K - 1] = 1;
    }
    matrix_pow(r, n - K, r);
    matrix_mul(l, r, l);
    int res = 1;
    for(int i = 0; i < K; ++i) {
        res = (long long)res * binpow(a[i], l[i][K - 1]) % md;
    }
    printf("%d", res);
    return 0;
}
