#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 100005;

int n;
LL md, a[N], f[N];
long double g[N];
vector<int> aj[N];

LL add(LL a, LL b) {
    a += b;
    if(a >= md) a -= md;
    return a;
}
LL mul(LL a, LL b) {
    LL c = 0;
    for(; b > 0; b >>= 1) {
        if(b & 1) c = add(c, a);
        a = add(a, a);
    }
    return c;
}

void dfs(int v, int p) {
    int best_u = -1;
    for(int u : aj[v]) {
        if(u == p) continue;
        dfs(u, v);
        if(best_u == -1 || g[best_u] < g[u]) {
            best_u = u;
        }
    }
    f[v] = a[v] % md;
    g[v] = log10l(a[v]);
    if(best_u != -1) {
        f[v] = mul(f[v], f[best_u]);
        g[v] += g[best_u];
    }
}

int main() {
    scanf("%d %lld", &n, &md);
    for(int i = 1; i <= n; ++i) {
        scanf("%lld", a + i);
    }
    for(int i = 1, u, v; i < n; ++i) {
        scanf("%d %d", &u, &v);
        aj[u].push_back(v);
        aj[v].push_back(u);
    }
    dfs(1, 0);
    printf("%lld", f[1]);
    return 0;
}
