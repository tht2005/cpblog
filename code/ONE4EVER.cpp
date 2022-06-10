#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL md;
LL add(LL a, LL b) {
    a += b;
    if(a >= md) a -= md;
    return a;
}
LL mul(LL a, LL b) {
    LL ret = 0;
    for(; b > 0; b >>= 1) {
        if(b & 1) ret = add(ret, a);
        a = add(a, a);
    }
    return ret;
}

const int K = 3;
void mat_mul(LL a[K][K], LL b[K][K], LL ret[K][K]) {
    static LL c[K][K];
    for(int i = 0; i < K; ++i) {
        for(int j = 0; j < K; ++j) {
            LL val = 0;
            for(int k = 0; k < K; ++k) {
                val += mul(a[i][k], b[k][j]);
            }
            c[i][j] = val % md;
        }
    }
    for(int i = 0; i < K; ++i) {
        for(int j = 0; j < K; ++j) {
            ret[i][j] = c[i][j];
        }
    }
}
void mat_pow(LL a[K][K], LL n, LL ret[K][K]) {
    static LL c[K][K];
    for(int i = 0; i < K; ++i) {
        for(int j = 0; j < K; ++j) {
            c[i][j] = (i == j);
        }
    }
    for(; n > 0; n >>= 1) {
        if(n & 1) mat_mul(c, a, c);
        mat_mul(a, a, a);
    }
    for(int i = 0; i < K; ++i) {
        for(int j = 0; j < K; ++j) {
            ret[i][j] = c[i][j];
        }
    }
}

LL a[K][K], b[K][K];

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        LL A, B, N;
        scanf("%lld %lld %lld %lld", &A, &B, &md, &N);
        A %= md;
        B %= md;
        if(N == 1) {
            printf("%lld\n", B);
        }
        else {
            a[0][0] = B;
            a[0][1] = add(mul(A, B), B);
            a[0][2] = 1;
            b[0][0] = b[0][1] = b[0][2] = b[1][2] = b[2][0] = 0;
            b[1][0] = b[2][2] = 1;
            b[1][1] = A;
            b[2][1] = B;
            mat_pow(b, N - 1, b);
            mat_mul(a, b, a);
            printf("%lld\n", a[0][0]);
        }
    }
    return 0;
}
