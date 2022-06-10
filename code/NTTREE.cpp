#include <bits/stdc++.h>

using namespace std;

const int N = 10004;
int n, f[N];
vector<pair<int, int>> aj[N];
long long res;

void dfs(int v, int p_) {
    f[v] = 1;
    for(const auto& [w, u] : aj[v]) {
        if(u == p_) continue;
        dfs(u, v);
        f[v] += f[u];
        res += (long long)w * f[u] * (n - f[u]);
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 1, u, v, w; i < n; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        aj[u].emplace_back(w, v);
        aj[v].emplace_back(w, u);
    }
    res = 0;
    dfs(0, -1);
    printf("%lld", res);
    return 0;
}
