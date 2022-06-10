#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
const int md = (int)1e9 + 7;

int n, res, f[N];
vector<pair<int, int>> aj[N];

void dfs(int v, int p_) {
    for(const auto& [w, u] : aj[v]) {
        if(u == p_) continue;
        dfs(u, v);
        int val = ((long long)(f[u] + 1) * w) % md;
        if((res += ((long long)f[v] * val) % md) >= md) res -= md;
        if((f[v] += val) >= md) f[v] -= val;
    }
    if((res += f[v]) >= md) res -= md;
}

int main() {
    scanf("%d", &n);
    for(int i = 1, u, v, w; i < n; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        aj[u].emplace_back(w, v);
        aj[v].emplace_back(w, u);
    }
    dfs(1, -1);
    printf("%d", res);
    return 0;
}
