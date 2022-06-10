#include <bits/stdc++.h>

using namespace std;

template<typename T> void ckmin(T& a, T b) {
    if(a > b) {
        a = b;
    }
}

typedef long long LL;
const LL INF = numeric_limits<LL>::max() / 2;

struct edge {
    int u, w;
};

const int N = 1003;
const int K = 15;

int s[K + 1];
LL d[K + 1][N], f[1 << K][K];
vector<edge> aj[N];

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < k; ++i) {
        scanf("%d", s + i);
        --s[i];
    }
    s[k] = 0;
    for(int u, v, w; m--; ) {
        scanf("%d %d %d", &u, &v, &w);
        aj[u - 1].push_back({ v - 1, w });
    }
    for(int o = 0; o <= k; ++o) {
        int src = s[o];
        LL* dd = d[o];
        for(int i = 0; i < n; ++i) {
            dd[i] = INF;
        }
        dd[src] = 0;
        vector<int> q(1, src);
        while(!q.empty()) {
            auto it = min_element(q.begin(), q.end(), [&](int i, int j) {
                return d[i] < d[j];
            });
            int v = *it;
            swap(*it, q.back());
            q.pop_back();
            for(const edge& e : aj[v]) {
                if(dd[e.u] == INF) {
                    q.push_back(e.u);
                }
                ckmin(dd[e.u], dd[v] + e.w);
            }
        }
    }
    for(int t = 1 << k; t--; ) {
        for(int i = 0; i < k; ++i) {
            f[t][i] = INF;
        }
    }
    for(int i = 0; i < k; ++i) {
        f[1 << i][i] = d[k][s[i]];
    }
    for(int t = 1; t < 1 << k; ++t) {
        for(int i = 0; i < k; ++i) {
            LL ft = f[t][i];
            if(ft == INF) continue;
            for(int j = 0; j < k; ++j) {
                if((t >> j & 1) || d[i][s[j]] == INF) continue;
                ckmin(f[t | (1 << j)][j], ft + d[i][s[j]]);
            }
        }
    }
    LL res = INF;
    for(int i = 0; i < k; ++i) {
        ckmin(res, f[(1 << k) - 1][i] + d[i][0]);
    }
    printf("%lld", (res == INF) ? -1 : res);
    return 0;
}
