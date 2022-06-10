#include <bits/stdc++.h>

using namespace std;

unsigned a[501][501], h[501], s[501];

int main() {
    unsigned m, n, k;
    scanf("%u %u %u", &m, &n, &k);
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf("%u", &a[i][j]);
        }
    }
    int res = -1, x, y, z, t;
    for(int u = 0; u < m; ++u) {
        memset(h, 0, n * sizeof *h);
        for(int d = u; d < m; ++d) {
            s[0] = 0;
            for(int i = 0; i < n; ++i) {
                h[i] += a[d][i];
                s[i + 1] = s[i] + h[i];
            }
            int len = -1, l, r;
            for(int i = n, j = n; i > 0; --i) {
                while(j > 0 && s[i] - s[j] < k) {
                    --j;
                }
                if(s[i] - s[j] < k) {
                    break;
                }
                if(len == -1 || len > i - j) {
                    len = i - j;
                    l = j;
                    r = i - 1;
                }
            }
            if(len != -1 && (res == -1 || res > (d - u + 1) * len)) {
                res = (d - u + 1) * len;
                x = u;
                y = l;
                z = d;
                t = r;
            }
        }
    }
    printf("%d", res);
    if(res != -1) printf("\n%d %d %d %d", x + 1, y + 1, z + 1, t + 1);
    return 0;
}
