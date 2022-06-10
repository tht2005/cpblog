#include <bits/stdc++.h>

using namespace std;

const int md = (int)1e9;
void add(int& a, int b) {
    a += b;
    if(a >= md) a -= md;
}

const int N = 102;
const int V = 30001;

int m, n, res, a[N][N], f[N][N];

int main() {
    scanf("%d %d", &m, &n);
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = m; i--; ) {
        f[i][n - 1] = 1;
        for(int j = n - 1; j--; ) {
            f[i][j] = 0;
            for(int x = i; x < m; ++x) {
                for(int y = j + (x == i); y < n; ++y) {
                    if(__gcd(a[i][j], a[x][y]) > 1) {
                        add(f[i][j], f[x][y]);
                    }
                }
            }
        }
        add(res, f[i][0]);
    }
    printf("%d", res);
    return 0;
}
