#include <bits/stdc++.h>

using namespace std;

const int N = 1003;

int f[N], g[N][2];
vector<int> aj[N];

void dfs(int v, int p) {
    int tot = 0;
    for(int u : aj[v]) {
        if(u == p) continue;
        dfs(u, v);
        tot += min(f[u], g[u][1]);
    }
    f[v] = 1;
    g[v][0] = 0;
    g[v][1] = INF;
    for(int u : aj[v]) {
        if(u == p) continue;
        f[v] += min(f[u], min(g[u][0], g[u][1]));
        g[v][0] += min(f[u], g[u][1]);
        g[v][1] = min(g[v][1], tot - min(f[u], g[u][1]) + f[u]);
    }
}

int main() {
    int n;
    while(scanf("%d", &n), n) {
        for(int i = 1, u, v; i < n; ++i) {
            scanf("%d %d", &u, &v);
            aj[u].push_back(v);
            aj[v].push_back(u);
        }
        dfs(1, -1);
        printf("%d\n", min(f[1], g[1][1]));
        for(int i = 1; i <= n; ++i) {
            aj[i].clear();
        }
    }
    return 0;
}
