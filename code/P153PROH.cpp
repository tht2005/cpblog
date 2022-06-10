#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
const int L = 17;

int h[N], f[N], tin[N], tout[N], p[N][L];
vector<int> aj[N];

bool anc(int v, int u) {
    return tin[v] <= tin[u] && tout[u] <= tout[v];
}
int lca(int v, int u) {
    if(anc(v, u)) return v;
    if(anc(u, v)) return u;
    for(int i = L; i--; ) {
        if(~p[v][i] && !anc(p[v][i], u)) {
            v = p[v][i];
        }
    }
    return p[v][0];
}

void dfs(int v, int p_) {
    memset(p[v], 0xff, sizeof(p[v]));
    p[v][0] = p_;
    for(int i = 0; i + 1 < L && ~p[v][i]; ++i) {
        p[v][i + 1] = p[p[v][i]][i];
    }
    tin[v] = ++(*tin);
    f[v] = 1;
    for(int u : aj[v]) {
        if(u == p_) continue;
        h[u] = h[v] + 1;
        dfs(u, v);
        f[v] += f[u];
    }
    tout[v] = (*tin);
}

int up(int v, int d) {
    for(int i = L; i--; ) {
        if(d >> i & 1) {
            v = p[v][i];
        }
    }
    return v;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1, u, v; i < n; ++i) {
        scanf("%d %d", &u, &v);
        aj[u].push_back(v);
        aj[v].push_back(u);
    }
    dfs(1, -1);
    int q;
    scanf("%d", &q);
    while(q--) {
        int u, v;
        scanf("%d %d", &u, &v);
        if(u == v) {
            printf("%d\n", n);
        }
        else {
            int x = lca(u, v), d = h[u] + h[v] - 2 * h[x];
            if(d & 1) {
                puts("0");
            }
            else {
                if(h[u] < h[v]) {
                    swap(u, v);
                }
                int cy = up(u, d / 2 - 1), y = p[cy][0];
                int res = n - f[cy];
                if(anc(y, v)) {
                    res -= f[up(v, d / 2 - 1)];
                }
                else {
                    res -= n - f[y];
                }
                printf("%d\n", res);
            }
        }
    }
    return 0;
}
