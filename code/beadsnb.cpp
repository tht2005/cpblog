#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
int a[N], b[N], f[N];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    memset(b, 0x3f, n * sizeof *b);
    for(int i = n; i--; ) {
        int j = lower_bound(b, b + n, a[i]) - b;
        b[j] = a[i];
        f[i] += j;
    }
    memset(b, 0x3f, n * sizeof *b);
    for(int i = n; i--; ) {
        int j = lower_bound(b, b + n, -a[i]) - b;
        b[j] = -a[i];
        f[i] += j;
    }
    printf("%d", *max_element(f, f + n) + 1);
    return 0;
}
