#include <bits/stdc++.h>

using namespace std;

const int N = 102;
const int M = 2003;

int n, m, x[N], y[N], f[N][M];
vector<int> aj[N];

void dfs(int v, int p) {
    memset(f[v], 0xff, (m + 1) * sizeof *f[v]);
    f[v][y[v]] = x[v];
    for(int u : aj[v]) {
        if(u == p) continue;
        dfs(u, v);
        for(int i = m; i >= 0; --i) {
            if(f[v][i] != -1) {
                for(int j = m - i; j >= 0; --j) {
                    if(f[u][j] != -1) {
                        f[v][i + j] = max(f[v][i + j], f[v][i] + f[u][j]);
                    }
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    x[1] = 0;
    for(int i = 2; i <= n; ++i) {
        scanf("%d", x + i);
    }
    y[1] = 0;
    for(int i = 2; i <= n; ++i) {
        scanf("%d", y + i);
    }
    for(int i = 1, u, v; i < n; ++i) {
        scanf("%d %d", &u, &v);
        aj[u].push_back(v);
        aj[v].push_back(u);
    }
    dfs(1, 0);
    printf("%d", *max_element(f[1], f[1] + 1 + m));
    return 0;
}
