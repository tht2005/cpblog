#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
int n, f[N], res[N];
vector<int> aj[N];

void update(int v, int p, int c) {
    res[v] = c;
    for(int u : aj[v]) {
        if(u == p) continue;
        update(u, v, c);
    }
}

void dfs(int v, int p) {
    f[v] = 1;
    vector<pair<int, int>> child;
    for(int u : aj[v]) {
        if(u == p) continue;
        dfs(u, v);
        f[v] += f[u];
        child.emplace_back(f[u], u);
    }
    if(p != -1) {
        child.emplace_back(n - f[v], p);
    }
    sort(child.rbegin(), child.rend());
    int cnt[3];
    cnt[0] = cnt[1] = cnt[2] = 0;
    for(auto& [x, u] : child) {
        int i = min_element(cnt, cnt + 3) - cnt;
        cnt[i] += x;
        x = i;
    }
    if(cnt[0] && cnt[1] && cnt[2] && max(cnt[0], max(cnt[1], cnt[2])) * 2 <= n) {
        res[v] = 0;
        for(const auto& [x, u] : child) {
            update(u, v, x + 1);
        }
        for(int i = 1; i <= n; ++i) {
            printf("%d ", res[i]);
        }
        exit(0);
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 1, u, v; i < n; ++i) {
        scanf("%d %d", &u, &v);
        aj[u].push_back(v);
        aj[v].push_back(u);
    }
    dfs(1, -1);
    puts("-1");
    return 0;
}
