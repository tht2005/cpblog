#include <bits/stdc++.h>

using namespace std;

const int N = 102;
const int V = 1000001;

int n, s, c[N], f[V];

int main() {
    scanf("%d %d", &n, &s);
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%d", c + i);
        for(int j = c[i]; j < V; ++j) {
            f[j] = min(f[j], f[j - c[i]] + 1);
        }
    }
    int res = (s < V) ? f[s] : s;
    if(s >= V) {
        for(int i = 0; i < n; ++i) {
            int k = (s - V) / c[i] + 1;
            res = min(res, f[s - k * c[i]] + k);
        }
    }
    printf("%d", res);
    return 0;
}
