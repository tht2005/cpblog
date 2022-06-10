#include <bits/stdc++.h>

using namespace std;

const int N = 20;
int a[N][N], f[1 << N];
long long c[1 << N];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    memset(f, 0xff, sizeof(f));
    f[(1 << n) - 1] = 0;
    c[(1 << n) - 1] = 1;
    for(int t = 1 << n; t --> 1; ) {
        int ff = f[t];
        long long cc = c[t];
        int j = __builtin_popcount(t) - 1;
        for(int i = 0; i < n; ++i) {
            if(t >> i & 1) {
                int nt = t ^ (1 << i);
                if(f[nt] < ff + a[j][i]) {
                    f[nt] = ff + a[j][i];
                    c[nt] = cc;
                }
                else if(f[nt] == ff + a[j][i]) {
                    c[nt] += cc;
                }
            }
        }
    }
    printf("%d %lld", f[0], c[0]);
    return 0;
}
