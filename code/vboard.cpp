#include <bits/stdc++.h>

using namespace std;

const int N = 502;
int f[N][N];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1, a; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            scanf("%d", &a);
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + ((i + j & 1) ? a : -a);
        }
    }
    int q;
    scanf("%d", &q);
    while(q--) {
        int x, y, u, v;
        scanf("%d %d %d %d", &x, &y, &u, &v);
        --x, --y;
        int res = f[u][v] - f[x][v] - f[u][y] + f[x][y];
        if(res < 0) res = -res;
        printf("%d\n", res);
    }
    return 0;
}
