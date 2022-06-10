#include <bits/stdc++.h>

using namespace std;

const int N = 202;
int n, match[N << 1], c[N][N];
unsigned l, r, res, m;
bool vst[N];

bool dfs(int v) {
    if(!vst[v]) {
        vst[v] = 1;
        for(int u = 0; u < n; ++u) {
            if(c[v][u] > m) {
                continue;
            }
            if(match[n + u] == -1 || dfs(match[n + u])) {
                match[v] = n + u;
                match[n + u] = v;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf("%d", c[i] + j);
        }
    }
    l = 0;
    r = numeric_limits<int>::max();
    res = r;
    while(l <= r) {
        m = l + ((r - l) >> 1);
        memset(match, 0xff, 2 * n * sizeof *match);
        bool f;
        do {
            f = 0;
            memset(vst, 0, n * sizeof *vst);
            for(int i = 0; i < n; ++i) {
                if(match[i] == -1) {
                    f |= dfs(i);
                }
            }
        } while(f);
        bool ok = 1;
        for(int i = 0; i < n; ++i) {
            if(match[i] == -1) {
                ok = 0;
                break;
            }
        }
        if(ok) {
            res = m;
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    printf("%u", res);
    return 0;
}
