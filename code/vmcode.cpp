#include <bits/stdc++.h>

using namespace std;

const int N = 2003;
const int INF = (int)1e9 + 7;

int f[N][N][2], g[N][N], cnt[26];
char s[N], a[N][N];

int main() {
    int m, n, k;
    scanf("%d %d %d %s", &m, &n, &k, s);
    for(int i = 0; i < m; ++i) {
        scanf("%s", a + i);
    }
    for(int i = 0; i < n; ++i) {
        f[m - 1][i][0] = (a[m - 1][i] > s[m - 1]);
        f[m - 1][i][1] = 1;
    }
    for(int i = m - 2; i >= 0; --i) {
        for(int j = 0; j < n; ++j) {
            unsigned val;
            if(a[i][j] < s[i]) {
                f[i][j][0] = 0;
            }
            else {
                val = 0;
                for(int k = j - 1; k <= j + 1; ++k) {
                    if(0 <= k && k < n) {
                        val += f[i + 1][k][a[i][j] > s[i]];
                    }
                }
                if(val > INF) val = INF;
                f[i][j][0] = val;
            }
            val = 0;
            for(int k = j - 1; k <= j + 1; ++k) {
                if(0 <= k && k < n) {
                    val += f[i + 1][k][1];
                }
            }
            if(val > INF) val = INF;
            f[i][j][1] = val;
        }
    }
    for(int i = 0; i < n; ++i) {
        g[0][i] = 1;
    }
    bool t = 0;
    for(int i = 0, c; i < m; ++i) {
        memset(cnt, 0, sizeof(cnt));
        for(int j = 0; j < n; ++j) {
            long long tmp = (long long)g[i][j] * f[i][j][t || a[i][j] > s[i]];
            if(tmp > INF) tmp = INF;
            if((cnt[a[i][j] - 'a'] += tmp) > INF) {
                cnt[a[i][j] - 'a'] = INF;
            }
        }
        for(c = t ? 0 : s[i] - 'a';; ++c) {
            if(k <= cnt[c]) {
                break;
            }
            k -= cnt[c];
        }
        putchar(c + 'a');
        if(c + 'a' > s[i]) {
            t = 1;
        }
        for(int j = 0; j < n; ++j) {
            if(a[i][j] == c + 'a') {
                for(int k = j - 1; k <= j + 1; ++k) {
                    if(0 <= k && k < n) {
                        if((g[i + 1][k] += g[i][j]) > INF) {
                            g[i + 1][k] = INF;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
