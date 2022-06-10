#include <bits/stdc++.h>

using namespace std;

const int N = 33;
int n;
long long k, res, f[N][N];

int main() {
    scanf("%d", &n);
    n = 2 * n + 1;
    f[n][0] = 1;
    for(int i = n - 1; i > 0; --i) {
        f[i][0] = f[i + 1][1];
        for(int j = 1; j <= n; ++j) {
            f[i][j] = f[i + 1][j - 1] + f[i + 1][j + 1];
        }
    }
    res = 1;
    scanf("%*d");
    for(int i = 1, x = 0, y; i < n; ++i) {
        scanf("%d", &y);
        if(x && x < y) {
            res += f[i + 1][x - 1];
        }
        x = y;
    }
    printf("%lld\n", res);
    scanf("%lld", &k);
    putchar('0');
    for(int i = 1, x = 0; i < n; ++i) {
        if(!x || k > f[i + 1][x - 1]) {
            k -= f[i + 1][x - 1];
            ++x;
        }
        else {
            --x;
        }
        printf(" %d", x);
    }
    return 0;
}

