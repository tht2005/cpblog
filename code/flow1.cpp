#include <bits/stdc++.h>

using namespace std;

struct edge {
    int u, f;
};

const int N = 1024;
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
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0, j; i < n; ++i) {
        ae(S, i, 1);
        char c = getchar();
        while(c < '0' || c > '9') {
            c = getchar();
        }
        while(1) {
            while(c < '0' || c > '9') {
                if(c == '\n' || c == EOF) {
                    goto out1;
                }
                c = getchar();
            }
            j = 0;
            while('0' <= c && c <= '9') {
                j = (j << 3) + (j << 1) + c - '0';
                c = getchar();
            }
            ae(i, n + j - 1, 1);
        }
out1:;
    }
    for(int i = 0; i < m; ++i) {
        ae(n + i, n + m + i, 1);
    }
    for(int i = 0, j; i < n; ++i) {
        ae(n + m + m + i, T, 1);
        char c = getchar();
        while(c < '0' || c > '9') {
            c = getchar();
        }
        while(1) {
            while(c < '0' || c > '9') {
                if(c == '\n' || c == EOF) {
                    goto out2;
                }
                c = getchar();
            }
            j = 0;
            while('0' <= c && c <= '9') {
                j = (j << 3) + (j << 1) + c - '0';
                c = getchar();
            }
            ae(n + m + j - 1, n + m + m + i, 1);
        }
out2:;
    }
    assert(calc() == n);
    for(int v = 0, l, r; v < m; ++v) {
        l = r = 0;
        for(int i : aj[n + v]) {
            const edge& e = edges[i];
            if(0 <= e.u && e.u < n && e.f) {
                l = e.u + 1;
                break;
            }
        }
        for(int i : aj[n + m + v]) {
            const edge& e = edges[i];
            if(n + m + m <= e.u && e.u < n + m + m + n && !e.f) {
                r = e.u - n - m - m + 1;
                break;
            }
        }
        printf("%d %d\n", l, r);
    }
    return 0;
}
