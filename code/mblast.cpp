#include <bits/stdc++.h>

using namespace std;

const int N = 2003;

int n, m, k, f[N][N];
char a[N], b[N];

int main() {
    scanf("%s %s %d", a + 1, b + 1, &k);
    n = strlen(a + 1);
    m = strlen(b + 1);
    f[0][0] = 0;
    for(int i = 1; i <= m; ++i) {
        f[0][i] = k * i;
    }
    for(int i = 1; i <= n; ++i) {
        f[i][0] = k * i;
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            f[i][j] = min(min(f[i - 1][j], f[i][j - 1]) + k, f[i - 1][j - 1] + abs(a[i] - b[j]));
        }
    }
    printf("%d", f[n][m]);
    return 0;
}
