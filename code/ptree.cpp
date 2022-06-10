#include <bits/stdc++.h>

using namespace std;

inline void ckmax(int& a, int b) {
    if(a < b) {
        a = b;
    }
}

const int N = 202;
const int INF = 1e7;

int n, p, a[N], sz[N], f[N][N][N];
vector<int> aj[N];

void dfs(int v, int p_) {
    if(~p_) {
        aj[v].erase(find(aj[v].begin(), aj[v].end(), p_));
    }
    f[v][0][1] = a[v];
    for(int i = 2; i <= n; ++i) {
        f[v][0][i] = -INF;
    }
    int cnt = 1;
    for(unsigned int i = 0; i < aj[v].size(); ++i) {
        int u = aj[v][i];
        dfs(u, v);
        int *pre = f[v][i], *nxt = f[v][i + 1];
        memcpy(nxt, pre, (n + 1) * sizeof(int));
        int *fu = f[u][aj[u].size()];
        for(int x = cnt; x > 0; --x) {
            for(int y = sz[u]; y > 0; --y) {
                ckmax(nxt[x + y], pre[x] + fu[y]);
            }
        }
        cnt += sz[u];
    }
    sz[v] = cnt;
}

int main() {
    scanf("%d %d", &n, &p);
    for(int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    for(int i = 1, u, v; i < n; ++i) {
        scanf("%d %d", &u, &v);
        --u, --v;
        aj[u].push_back(v);
        aj[v].push_back(u);
    }
    dfs(0, -1);
    int best = 0;
    for(int i = 1; i < n; ++i) {
        if(f[best][aj[best].size()][p] < f[i][aj[i].size()][p]) {
            best = i;
        }
    }
    int top = 1;
    a[0] = best;
    sz[0] = p;
    while(top) {
        int v = a[--top], x = sz[top];
        printf("%d ", v + 1);
        for(int i = aj[v].size(); i--; ) {
            int *pre = f[v][i], *nxt = f[v][i + 1];
            int u = aj[v][i], *fu = f[u][aj[u].size()];
            for(int j = 0;; ++j) {
                if(nxt[x] == pre[x - j] + fu[j]) {
                    if(j) {
                        a[top] = u;
                        sz[top++] = j;
                        x -= j;
                    }
                    break;
                }
            }
        }
    }
    return 0;
}
