#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
int n, a[N], f[N], l[N], r[N];

void add(int x) {
    for(; x < n; x |= x + 1) {
        ++f[x];
    }
}
int query(int x) {
    int ret = 0;
    for(; x >= 0; x = (x & (x + 1)) - 1) {
        ret += f[x];
    }
    return ret;
}

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%d", a + i);
            --a[i];
        }
        memset(f, 0, n * sizeof *f);
        for(int i = 0; i < n; ++i) {
            l[i] = i - query(a[i]);
            add(a[i]);
        }
        memset(f, 0, n * sizeof *f);
        for(int i = n; i--; ) {
            r[i] = query(a[i] - 1);
            add(a[i]);
        }
        long long res = 0;
        for(int i = 0; i < n; ++i) {
            res += (long long)l[i] * r[i];
        }
        printf("%lld\n", res);
    }
    return 0;
}
