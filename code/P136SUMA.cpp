#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

struct dt {
    int a, b, h, i;
    bool operator< (const dt& b) const {
        return a < b.a;
    }
};

const int N = 200005;
const int M = 1000006;

LL dp[N];
dt a[N];

LL f[M];
void update(int x, LL d) {
    for(; x < M; x |= x + 1) {
        f[x] = max(f[x], d);
    }
}
LL query(int x) {
    LL ret = 0;
    for(; x >= 0; x = (x & (x + 1)) - 1) {
        ret = max(ret, f[x]);
    }
    return ret;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d %d %d", &a[i].a, &a[i].b, &a[i].h);
        a[i].i = i;
    }
    sort(a, a + n);
    for(int i = 0; i < n; ++i) {
        dp[i] = query(a[i].a) + a[i].h;
        update(a[i].b, dp[i]);
    }
    int i = max_element(dp, dp + n) - dp;
    printf("%lld\n%d", dp[i], a[i].i + 1);
    for(int j = i; j--; ) {
        if(a[j].b <= a[i].a && dp[j] + a[i].h == dp[i]) {
            printf(" %d", a[j].i + 1);
            i = j;
        }
    }
    return 0;
}
