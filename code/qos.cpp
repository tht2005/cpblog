#include <bits/stdc++.h>

using namespace std;

const int N = 1003;
const int c_max = 100;
const int INF = 1e9 + 7;

int t, d[N];
vector<int> f[N];
vector<pair<int, int>> aj[N], rev_aj[N];

int calc(int v, int L) {
    if(L < d[v]) return 0;
    while(!(L - d[v] < (int)f[v].size())) {
        f[v].push_back(-1);
    }
    if(~f[v][L - d[v]]) return f[v][L - d[v]];
    int res = (v == t);
    for(const auto& [u, w] : aj[v]) {
        res += calc(u, L - w);
        if(res > INF) {
            res = INF;
            break;
        }
    }
    return f[v][L - d[v]] = res;
}

int main() {
    int n, m, k;
    scanf("%d %d %d %d", &n, &m, &t, &k);
    int c_min = INF;
    for(int u, v, w; m--; ) {
        scanf("%d %d %d", &u, &v, &w);
        aj[u].emplace_back(v, w);
        rev_aj[v].emplace_back(u, w);
        if(c_min > w) {
            c_min = w;
        }
    }
    for(int i = 1; i <= n; ++i) {
        d[i] = INF;
    }
    priority_queue<pair<int, int>> q;
    q.emplace(d[t] = 0, t);
    while(!q.empty()) {
        int v = q.top().second, dv = -q.top().first;
        q.pop();
        if(dv != d[v]) continue;
        for(const auto& [u, w] : rev_aj[v]) {
            if(d[u] > dv + w) {
                q.emplace(-(d[u] = dv + w), u);
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        sort(aj[i].begin(), aj[i].end());
    }
    int v = 1, tot = d[1] + c_min;
    if(calc(1, tot) < k) {
        puts("-1");
        return 0;
    }
    vector<int> res;
    while(1) {
        res.push_back(v);
        if(v == t) {
            if(k == 1) {
                break;
            }
            --k;
        }
        for(const auto& [u, w] : aj[v]) {
            int val = calc(u, tot - w);
            if(k <= val) {
                v = u;
                tot -= w;
                break;
            }
            k -= val;
        }
    }
    printf("%d\n", (int)res.size());
    for(int i : res) {
        printf("%d ", i);
    }
    return 0;
}
