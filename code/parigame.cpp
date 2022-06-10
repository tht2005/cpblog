#include <bits/stdc++.h>

using namespace std;

const int N = 502;
int r[N][N], c[N][N];
bool f[N][N];

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        int n;
        scanf("%d", &n);
        for(int i = 1, a; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                scanf("%d", &a);
                r[i][j] = r[i][j - 1] ^ (a & 1);
                c[i][j] = c[i - 1][j] ^ (a & 1);
                f[i][j] = 0;
                if(!r[i][j] && !f[i - 1][j]) {
                    f[i][j] = 1;
                }
                if(!c[i][j] && !f[i][j - 1]) {
                    f[i][j] = 1;
                }
            }
        }
        puts(f[n][n] ? "YES" : "NO");
    }
    return 0;
}
