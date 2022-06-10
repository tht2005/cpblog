#include <bits/stdc++.h>

using namespace std;

struct edge {
    int u, f;
};

const int N = 105;
int S, T;
const int INF = numeric_limits<int>::max() / 2;

int d[N], q[N];
size_t ptr[N];
vector<int> aj[N];
vector<edge> edges;

void ae(int u, int v, int c) {
    aj[u].push_back(edges.size());
    edges.push_back({v, c});
    aj[v].push_back(edges.size());
    edges.push_back({u, 0});
}
bool bfs() {
    int fr = 0, bk = 0;
    q[bk++] = S;
    memset(d, 0xff, sizeof(d));
    d[S] = 0;
    while(fr < bk) {
        int v = q[fr++];
        for(int i : aj[v]) {
            const edge& e = edges[i];
            if(e.f && d[e.u] == -1) {
                d[e.u] = d[v] + 1;
                if(e.u == T) {
                    return 1;
                }
                q[bk++] = e.u;
            }
        }
    }
    return 0;
}
int dfs(int v, int f) {
    if(v == T) {
        return f;
    }
    for(size_t& p = ptr[v]; p < aj[v].size(); ++p) {
        int i = aj[v][p];
        const edge& e = edges[i];
        if(e.f && d[e.u] == d[v] + 1) {
            int val = dfs(e.u, min(f, e.f));
            if(val) {
                edges[i].f -= val;
                edges[i ^ 1].f += val;
                return val;
            }
        }
    }
    return 0;
}
int calc() {
    int totf = 0, df;
    while(bfs()) {
        memset(ptr, 0, sizeof(ptr));
        while(df = dfs(S, INF)) {
            totf += df;
        }
    }
    return totf;
}

bool vst[N];
vector<pair<int, int>> g[N];
bool check(int v, int t, int c) {
    if(v == t) {
        return 1;
    }
    vst[v] = 1;
    for(const auto& [w, u] : g[v]) {
        if(c < w && !vst[u] && check(u, t, c)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    while(m--) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g[u].emplace_back(w, v);
        g[v].emplace_back(w, u);
    }
    scanf("%d %d", &S, &T);
    int l = 1, r = 100, res = r;
    while(l <= r) {
        int v = (l + r) >> 1;
        memset(vst, 0, sizeof(vst));
        if(check(S, T, v)) {
            l = v + 1;
        }
        else {
            res = v;
            r = v - 1;
        }
    }
    for(int v = 1; v <= n; ++v) {
        for(const auto& [w, u] : g[v]) {
            if(res < w) {
                ae(v, u, INF);
            }
            else {
                ae(v, u, 1);
            }
        }
    }
    printf("%d", calc());
    memset(vst, 0, sizeof(vst));
    int top = 1;
    q[0] = S;
    vst[S] = 1;
    while(top) {
        int v = q[--top];
        for(int i : aj[v]) {
            const edge& e = edges[i];
            if(e.f && !vst[e.u]) {
                vst[e.u] = 1;
                q[top++] = e.u;
            }
        }
    }
    for(int v = 1; v <= n; ++v) {
        for(const auto& [w, u] : g[v]) {
            if(vst[v] != vst[u] && v < u) {
                printf("\n%d %d", v, u);
            }
        }
    }
    return 0;
}
