#include <bits/stdc++.h>

using namespace std;

struct edge {
    int u, f;
};

const int N = 52;
const int S = 0;
const int T = 25;
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
    int n;
    scanf("%d", &n);
    while(n--) {
        char a, b;
        int f;
        scanf(" %c %c %d", &a, &b, &f);
        int x = (a < 'a' || a > 'z') ? (a - 'A') : (26 + a - 'a'), y = (b < 'a' || b > 'z') ? (b - 'A') : (26 + b - 'a');
        ae(x, y, f);
        ae(y, x, f);
    }
    printf("%d", calc());
    return 0;
}
