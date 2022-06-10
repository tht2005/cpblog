#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void rd(int& n) {
    char c = getchar(); while(c < '0' || c > '9') c = getchar();
    n = 0; while('0' <= c && c <= '9') n = (n << 3) + (n << 1) + c - '0', c = getchar();
}

const int N = 1000;

void mat_mul(int n, int a[N], int b[N][N], int ret[N]) {
    for(int i = 0; i < n; ++i) {
        int val = 0;
        for(int j = 0; j < n; ++j) {
            val += a[j] * b[j][i];
        }
        ret[i] = val % 10;
    }
}

int a[N][N], b[N][N], c[N][N], d[N], e[N], f[N];

int main() {
    int q;
    rd(q);
    while(q--) {
        int n;
        rd(n);
        for(int i = 0; i < n; ++i) {
            char ch = getchar();
            while(ch < '0' || ch > '9') ch = getchar();
            for(int j = 0; j < n; ++j) {
                a[i][j] = ch - '0';
                ch = getchar();
            }
        }
        for(int i = 0; i < n; ++i) {
            char ch = getchar();
            while(ch < '0' || ch > '9') ch = getchar();
            for(int j = 0; j < n; ++j) {
                b[i][j] = ch - '0';
                ch = getchar();
            }
        }
        for(int i = 0; i < n; ++i) {
            char ch = getchar();
            while(ch < '0' || ch > '9') ch = getchar();
            for(int j = 0; j < n; ++j) {
                c[i][j] = ch - '0';
                ch = getchar();
            }
        }
        for(int t = 10; t--; ) {
            for(int i = 0; i < n; ++i) {
                d[i] = (unsigned)rng() % 10;
            }
            mat_mul(n, d, a, e);
            mat_mul(n, e, b, f);
            mat_mul(n, d, c, e);
            for(int i = 0; i < n; ++i) {
                if(e[i] != f[i]) {
                    goto no;
                }
            }
        }
        puts("YES");
        continue;
no:;
        puts("NO");
    }
    return 0;
}
