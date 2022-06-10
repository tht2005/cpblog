#include <bits/stdc++.h>

using namespace std;

int f[31][1 << 5];

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        int n, m;
        scanf("%d %d", &n, &m);
        if(n > m) {
            swap(n, m);
        }
        for(int i = 1 << n; i--; ) {
            f[1][i] = 1;
        }
        for(int i = 2; i <= m; ++i) {
            memset(f[i], 0, sizeof(f[i]));
        }
        for(int i = 1; i < m; ++i) {
            for(int j = 1 << n; j--; ) {
                int ft = f[i][j];
                if(ft == 0) continue;
                for(int k = 1 << n; k--; ) {
                    int x = j & k;
                    if(x & (x >> 1)) continue;
                    x = ~(j | k) & ((1 << n) - 1);
                    if(x & (x >> 1)) continue;
                    f[i + 1][k] += ft;
                }
            }
        }
        int res = 0;
        for(int i = 1 << n; i--; ) {
            res += f[m][i];
        }
        printf("%d\n", res);
    }
    return 0;
}
