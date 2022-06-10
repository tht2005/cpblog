#include <bits/stdc++.h>

using namespace std;

struct edge {
    int u, f, c;
};

const int N = 1000;
const int S = N - 2, S2 = N - 3;
const int T = N - 1;
const int INF = numeric_limits<int>::max() / 2;

int d[N], p[N], pre[N];
vector<int> aj[N];
vector<edge> edges;

void ae(int u, int v, int f, int c) {
    aj[u].push_back(edges.size());
    edges.push_back({v, f, c});
    aj[v].push_back(edges.size());
    edges.push_back({u, 0, -c});
}
bool ckmin(int& a, int b) {
    return (a > b) ? (a = b, 1) : 0;
}
bool dijkstra() {
    for(int i = 0; i < N; ++i) {
        d[i] = INF;
    }
    using dt = pair<int, int>;
    priority_queue<dt, vector<dt>, greater<dt>> q;
    q.emplace(d[S] = 0, S);
    while(!q.empty()) {
        auto [dv, v] = q.top();
        q.pop();
        if(dv != d[v]) {
            continue;
        }
        for(int id : aj[v]) {
            const edge& e = edges[id];
            if(e.f && ckmin(d[e.u], dv + e.c + p[v] - p[e.u])) {
                pre[e.u] = id;
                q.emplace(d[e.u], e.u);
            }
        }
    }
    return d[T] != INF;
}
pair<int, int> calc() {
    for(int t = 0; t < N; ++t) {
        for(int i = 0; i < N; ++i) {
            for(int id : aj[i]) {
                const edge& e = edges[id];
                if(e.f) {
                    ckmin(p[e.u], p[i] + e.c);
                }
            }
        }
    }
    int totf = 0, totc = 0;
    while(dijkstra()) {
        for(int i = 0; i < N; ++i) {
            p[i] += d[i];
        }
        int df = INF;
        for(int i = T; i != S; i = edges[pre[i] ^ 1].u) {
            ckmin(df, edges[pre[i]].f);
        }
        totf += df;
        totc += (p[T] - p[S]) * df;
        for(int i = T; i != S; i = edges[pre[i] ^ 1].u) {
            edges[pre[i]].f -= df;
            edges[pre[i] ^ 1].f += df;
        }
    }
    return pair<int, int> (totf, totc);
}

int main() {
    int n, m, k, a[30][30];
    while(~scanf("%d %d %d", &n, &m, &k)) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                scanf("%d", a[i] + j);
            }
        }
        for(int i = 0; i < N; ++i) {
            p[i] = 0;
            aj[i].clear();
        }
        edges.clear();
        ae(S, S2, k, 0);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if((i + j) & 1) {
                    ae(i * m + j, T, 1, 0);
                }
                else {
                    ae(S2, i * m + j, 1, 0);
                    if(i) {
                        ae(i * m + j, (i - 1) * m + j, 1, -a[i][j] * a[i - 1][j]);
                    }
                    if(i + 1 < n) {
                        ae(i * m + j, (i + 1) * m + j, 1, -a[i][j] * a[i + 1][j]);
                    }
                    if(j) {
                        ae(i * m + j, i * m + j - 1, 1, -a[i][j] * a[i][j - 1]);
                    }
                    if(j + 1 < m) {
                        ae(i * m + j, i * m + j + 1, 1, -a[i][j] * a[i][j + 1]);
                    }
                }
            }
        }
        printf("%d\n", -calc().second);
    }
    return 0;
}
