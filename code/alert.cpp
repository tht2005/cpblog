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

bool vst[N];
void partition(int s) {
    int top = 1;
    q[0] = s;
    vst[s] = 1;
    while(top) {
        int v = q[--top];
        for(int i : aj[v]) {
            const edge& e = edges[i];
            if(e.f && !vst[e.u]) {
                q[top++] = e.u;
                vst[e.u] = 1;
            }
        }
    }
}

int main() {
    int n, L;
    scanf("%d %d", &n, &L);
    while(L--) {
        int i;
        scanf("%d", &i);
        ae(i, T, INF);
    }
    int C;
    scanf("%d", &C);
    while(C--) {
        int i;
        scanf("%d", &i);
        ae(S, i, INF);
    }
    int m, tot = 0;
    scanf("%d", &m);
    while(m--) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        ae(x, y, z);
        ae(y, x, z);
        tot += z;
    }
    printf("%d", tot - calc());
    partition(S);
    vector<int> xhcn;
    for(int i = 1; i <= n; ++i) {
        if(!vst[i]) {
            xhcn.push_back(i);
        }
    }
    printf(" %d\n", (int)xhcn.size());
    for(int v : xhcn) {
        printf("%d ", v);
    }
    return 0;
}
