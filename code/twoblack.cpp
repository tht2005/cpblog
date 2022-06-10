#include <bits/stdc++.h>

using namespace std;

struct edge {
    int u, f;
};

const int N = 205;
const int S = N - 1;
const int T = N - 2;
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

vector<int> o[101];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        char c = getchar();
        while(c < '0' || c > '9') {
            c = getchar();
        }
        for(int j = 0; j < m; ++j) {
            if(c == '1') {
                o[i].push_back(j);
            }
            c = getchar();
        }
    }
    int l = 1, r = n, res = n;
    while(l <= r) {
        int v = (l + r) >> 1;
        for(int i = 0; i < N; ++i) {
            aj[i].clear();
        }
        edges.clear();
        for(int i = 0; i < n; ++i) {
            ae(S, i, 2);
            for(int j : o[i]) {
                ae(i, n + j, 1);
            }
        }
        for(int i = 0; i < m; ++i) {
            ae(n + i, T, v);
        }
        if(calc() == n + n) {
            res = v;
            r = v - 1;
        }
        else {
            l = v + 1;
        }
    }
    printf("%d", res);
    return 0;
}
