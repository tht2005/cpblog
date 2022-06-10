#include <bits/stdc++.h>

using namespace std;

const array<int, 5> pw = { 1, 5, 25, 125, 625 };
int a[4][4], b[4][5], f[5][625];

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    memset(f, 0xff, sizeof(f));
    f[0][0] = 0;
    for(int i = 0; i < m; ++i) {
        for(int j = pw[n]; j--; ) {
            int ft = f[i][j];
            if(ft == -1) continue;
            for(int t = 1 << n; t--; ) {
                int nj = j, cost = 0, cur = 0;
                for(int k = 0; k < n; ++k) {
                    int x = (j / pw[k]) % 5;
                    if(t >> k & 1) {
                        nj += pw[k];
                        if(cur) {
                            cost += cur;
                            cur = 0;
                        }
                    }
                    else {
                        cur = cur * 10 + a[i][k];
                        if(x) {
                            nj -= x * pw[k];
                            cost += b[k][x];
                        }
                    }
                }
                if(cur) {
                    cost += cur;
                }
                f[i + 1][nj] = max(f[i + 1][nj], ft + cost);
            }
        }
        for(int j = 0; j < n; ++j) {
            for(int k = i; k >= 0; --k) {
                b[j][k + 1] = b[j][k] * 10 + a[i][j];
            }
        }
    }
    int res = -1;
    for(int i = pw[n]; i--; ) {
        if(f[m][i] == -1) continue;
        int cost = 0;
        for(int j = 0; j < n; ++j) {
            int x = (i / pw[j]) % 5;
            if(x) {
                cost += b[j][x];
            }
        }
        res = max(res, f[m][i] + cost);
    }
    printf("%d", res);
    return 0;
}
