#include <bits/stdc++.h>

using namespace std;

struct edge {
    int u, f;
};

const int N = 475;
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

int main() {
    int n, a[31][31], o[31];
    scanf("%d", &n);
    memset(o, 0, n * sizeof *o);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf("%d", a[i] + j);
            if(a[i][j] == 1) {
                ++o[i];
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < N; ++j) {
            aj[j].clear();
        }
        edges.clear();
        int x = 0;
        for(int j = 0; j < n; ++j) {
            if(a[i][j]) {
                ++x;
            }
        }
        int cnt = n;
        for(int j = 0; j < n; ++j) {
            if(j == i) {
                continue;
            }
            for(int k = j + 1; k < n; ++k) {
                if(k == i) {
                    continue;
                }
                if(a[j][k] == 2) {
                    ae(S, cnt, 1);
                    ae(cnt, j, 1);
                    ae(cnt, k, 1);
                    ++cnt;
                }
            }
        }
        for(int j = 0; j < n; ++j) {
            if(x < o[j]) {
                goto lose;
            }
            ae(j, T, x - o[j]);
        }
        if(calc() != cnt - n) {
            goto lose;
        }
        putchar('1');
        continue;
lose:;
        putchar('0');
    }
    return 0;
}
