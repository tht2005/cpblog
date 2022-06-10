#include <bits/stdc++.h>

using namespace std;

const int H = 31;
int f[H][H][2];

int main() {
    int n, k;
    while(~scanf("%d %d", &n, &k)) {
        int h = 32 - __builtin_clz(n);
        memset(f, 0, sizeof(f));
        f[h - 1][0][0] = 1;
        for(int i = h - 2; i > 0; --i) {
            f[i][0][1] = 1;
        }
        for(int i = h - 1; i--; ) {
            int b = n >> i & 1;
            for(int j = 0; j < h; ++j) {
                for(int t = 0; t < 2; ++t) {
                    int ft = f[i + 1][j][t];
                    if(ft == 0) continue;
                    f[i][j + 1][t || b] += ft;
                    if(t || b) f[i][j][t] += ft;
                }
            }
        }
        long long res = 0;
        for(int i = 1; i < h; ++i) {
            res += (long long)((i - 1) / k + 1) * (f[0][i][0] + f[0][i][1]);
        }
        printf("%lld\n", res);
    }
    return 0;
}
