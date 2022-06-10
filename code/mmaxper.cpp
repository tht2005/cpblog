#include <bits/stdc++.h>

using namespace std;

const int N = 1003;
int n, a[N], b[N], f[N], g[N];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", a + i, b + i);
    }
    f[0] = b[0];
    g[0] = a[0];
    for(int i = 1; i < n; ++i) {
        f[i] = max(f[i - 1] + abs(a[i] - a[i - 1]) + b[i], g[i - 1] + abs(a[i] - b[i - 1]) + b[i]);
        g[i] = max(f[i - 1] + abs(b[i] - a[i - 1]) + a[i], g[i - 1] + abs(b[i] - b[i - 1]) + a[i]);
    }
    printf("%d", max(f[n - 1], g[n - 1]));
    return 0;
}
