#include <bits/stdc++.h>

using namespace std;

const int N = 502;
int a[N][N], trc[N][N];
bool f[N][N];
char r[N << 1];

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf("%d", a[i] + j);
            trc[i][j] = -1;
        }
    }
    f[m][n - 1] = 1;
    for(int i = m; i--; ) {
        for(int j = n; j--; ) {
            f[i][j] = (a[i][j] != 2) && (f[i + 1][j] || f[i][j + 1]);
        }
    }
    trc[0][0] = 0;
    for(int s = 0; s < m + n - 2; ++s) {
        for(int t = 2; t--; ) {
            bool ok = 0;
            for(int i = min(s, m - 1), j = s - i; 0 <= i && j < n; --i, ++j) {
                if(~trc[i][j]) {
                    if(i + 1 < m && a[i + 1][j] == t && f[i + 1][j]) {
                        trc[i + 1][j] = 0;
                        ok = 1;
                    }
                    if(j + 1 < n && a[i][j + 1] == t && f[i][j + 1]) {
                        trc[i][j + 1] = 1;
                        ok = 1;
                    }
                }
            }
            if(ok) {
                break;
            }
        }
    }
    int sz = 0;
    for(int i = m - 1, j = n - 1; i >= 0 && j >= 0; ) {
        r[sz++] = a[i][j] + '0';
        if(trc[i][j]) {
            --j;
        }
        else {
            --i;
        }
    }
    for(int i = sz; i--; ) {
        putchar(r[i]);
    }
    return 0;
}
