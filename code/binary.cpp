#include <bits/stdc++.h>

using namespace std;

const int H = 31;

int nCr[H][H], f[H][H];

int main() {
    for(int i = 0; i < H; ++i) {
        nCr[i][0] = nCr[i][i] = 1;
        for(int j = 1, k = i >> 1; j <= k; ++j) {
            nCr[i][j] = nCr[i][i - j] = nCr[i - 1][j] + nCr[i - 1][j - 1];
        }
    }
    f[0][1] = 1;
    for(int i = 1; i < H; ++i) {
        for(int j = 0; j < H; ++j) {
            f[i][j] = f[i - 1][j] + nCr[i][j];
        }
    }
    for(int n, k; scanf("%d %d", &n, &k) == 2; ) {
        if(n == 0) {
            putchar('0' + (k == 1));
            putchar('\n');
        }
        else {
            if(k < 0 || k >= H) {
                putchar('0');
                putchar('\n');
            }
            else {
                int h = 32 - __builtin_clz(n);
                int res = (h < 2) ? 0 : f[h - 2][k], z = 0;
                for(int i = h; i--; ) {
                    if(n >> i & 1) {
                        if(i + 1 != h && z < k) {
                            res += nCr[i][k - 1 - z];
                        }
                    }
                    else {
                        ++z;
                    }
                }
                if(z == k) ++res;
                printf("%d\n", res);
            }
        }
    }
    return 0;
}
