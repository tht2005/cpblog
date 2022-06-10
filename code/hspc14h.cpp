#include <bits/stdc++.h>

using namespace std;

const int N = 1505;
int a[N][N], b[N][N], f[N][N];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            char c;
            int x;
            scanf(" %c%d", &c, &x);
            if(c == 'A') {
                a[i][j] = x;
            }
            else {
                b[i][j] = x;
            }
            a[i][j] += a[i][j - 1];
        }
        for(int j = m; j > 0; --j) {
            b[i][j] += b[i][j + 1];
        }
    }
    f[1][1] = b[1][2];
    for(int i = 1; i <= n; ++i) {
        for(int j = 1 + (i == 1); j <= m; ++j) {
            if(i != 1) {
                f[i][j] = f[i - 1][j] + a[i][j - 1] + b[i][j + 1];
            }
            if(j != 1) {
                f[i][j] = max(f[i][j], f[i][j - 1] - b[i][j] + b[i][j + 1]);
            }
            if(i != 1 && j != 1) {
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + a[i][j - 1] + b[i][j + 1]);
            }
        }
    }
    printf("%d", f[n][m]);
    return 0;
}
