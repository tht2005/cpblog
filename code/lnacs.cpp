#include <bits/stdc++.h>

using namespace std;

const int N = 1003;
int n, m, a[N], b[N], f[N][N];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    for(int i = 1; i <= m; ++i) {
        scanf("%d", b + i);
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if(a[i] == b[j]) {
                f[i][j] = max(f[i][j], (i > 1 && j > 1) ? f[i - 2][j - 2] + 1 : 1);
            }
        }
    }
    printf("%d", f[n][m]);
    return 0;
}
