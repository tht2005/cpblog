#include <bits/stdc++.h>

using namespace std;

const int N = 2003;
const int NSTATE = 1 << 9;

int n, m, a[N], b[N], f[NSTATE], g[NSTATE];

int main() {
    scanf("%d", &m);
    for(int i = 0; i < m; ++i) {
        scanf("%d", a + i);
    }
    sort(a, a + m);
    n = 0;
    for(int i = 0, j = 0; i < m; i = j) {
        while(j < m && a[i] == a[j]) {
            ++j;
        }
        a[n] = a[i];
        b[n] = j - i;
        ++n;
    }
    memset(f, 0xff, sizeof(f));
    f[0] = 0;
    for(int i = 0; i < n; ++i) {
        int t = 0;
        for(int j = 0; j < 9 && j < i; ++j) {
            int k = a[i] - a[i - 1 - j];
            if(k == 1 || k == 8 || k == 9) {
                t |= 1 << j;
            }
        }
        memcpy(g, f, sizeof(f));
        memset(f, 0xff, sizeof(f));
        for(int j = 0; j < NSTATE; ++j) {
            int ft = g[j];
            if(ft == -1) continue;
            f[(j << 1) & ~NSTATE] = max(f[(j << 1) & ~NSTATE], ft);
            if(!(j & t)) f[(j << 1 | 1) & ~NSTATE] = max(f[(j << 1 | 1) & ~NSTATE], ft + b[i]);
        }
    }
    printf("%d", m - (*max_element(f, f + NSTATE)));
    return 0;
}
