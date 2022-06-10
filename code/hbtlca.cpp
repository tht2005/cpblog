#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
const int L = 17;

int tin[N], tout[N], p[N][L];
vector<int> aj[N];

void dfs(int v, int p_) {
    memset(p[v], 0xff, sizeof(p[v]));
    p[v][0] = p_;
    for(int i = 0; i + 1 < L && ~p[v][i]; ++i) {
        p[v][i + 1] = p[p[v][i]][i];
    }
    tin[v] = ++(*tin);
    for(int u : aj[v]) {
        if(u == p_) continue;
        dfs(u, v);
    }
    tout[v] = (*tin);
}

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

int main() {
    int n;
    while(scanf("%d", &n), n) {
        for(int i = 1, u, v; i < n; ++i) {
            scanf("%d %d", &u, &v);
            aj[u].push_back(v);
            aj[v].push_back(u);
        }
        dfs(1, -1);
        int r = 1, q;
        scanf("%d", &q);
        while(q--) {
            char o;
            scanf(" %c", &o);
            if(o == '!') {
                scanf("%d", &r);
            }
            else {
                int u, v;
                scanf("%d %d", &u, &v);
                printf("%d\n", lca(u, v) ^ lca(u, r) ^ lca(v, r));
            }
        }
        for(int i = 1; i <= n; ++i) {
            aj[i].clear();
        }
    }
    return 0;
}
