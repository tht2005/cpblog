#include <bits/stdc++.h>

using namespace std;

const int N = 130;
char a[N][N];
int f[N << 1][N][N];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf(" %c", &a[i][j]);
        }
    }
    memset(f, 0xff, sizeof(f));
    f[0][0][0] = (a[0][0] == '*');
    for(int s = 0; s < m + n - 2; ++s) {
        for(int i = min(s, m - 1); 0 <= i && s - i < n; --i) {
            for(int j = i; 0 <= j && s - j < n; --j) {
                int ft = f[s][i][j];
                if(ft == -1) continue;
                for(int t = 0; t < 4; ++t) {
                    int ni = i + (t & 1), nj = j + (t >> 1 & 1);
                    if(ni >= m || s + 1 - ni >= n || nj >= m || s + 1 - nj >= n || a[ni][s + 1 - ni] == '#' || a[nj][s + 1 - nj] == '#') continue;
                    f[s + 1][ni][nj] = max(f[s + 1][ni][nj], ft + (a[ni][s + 1 - ni] == '*') + (ni != nj && a[nj][s + 1 - nj] == '*'));
                }
            }
        }
    }
    printf("%d", max(0, f[m + n - 2][m - 1][m - 1]));
    return 0;
}
