#include <bits/stdc++.h>

using namespace std;

const int N = 402;
int f[N];
vector<int> aj[N];

void dfs(int v) {
    if(aj[v].empty()) {
        f[v] = 1;
    }
    else {
        for(int u : aj[v]) {
            dfs(u);
        }
        sort(aj[v].begin(), aj[v].end(), [&](int i, int j) {
             return f[i] > f[j];
        });
        f[v] = 0;
        for(int i = 0; i < aj[v].size(); ++i) {
            f[v] = max(f[v], f[aj[v][i]] + i);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int i, m;
    while(~scanf("%d %d", &i, &m)) {
        while(m--) {
            int v;
            scanf("%d", &v);
            aj[i].push_back(v);
        }
    }
    dfs(1);
    printf("%d", f[1]);
    return 0;
}
