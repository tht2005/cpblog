#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
int n, res, a[N], h[N], l[N], r[N];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    for(int i = 0; i <= n; ++i) {
        h[i] = 2e9;
    }
    for(int i = 0; i < n; ++i) {
        l[i] = lower_bound(h + 1, h + 1 + n, a[i]) - h;
        h[l[i]] = a[i];
    }
    for(int i = 0; i <= n; ++i) {
        h[i] = 2e9;
    }
    for(int i = n; i--; ) {
        r[i] = lower_bound(h + 1, h + 1 + n, a[i]) - h;
        h[r[i]] = a[i];
    }
    for(int i = 0; i < n; ++i) {
        res = max(res, min(l[i], r[i]));
    }
    printf("%d", 2 * res - 1);
    return 0;
}
