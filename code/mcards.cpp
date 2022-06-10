#include <bits/stdc++.h>

using namespace std;

const int N = 402;
int val[4], x[N], y[N];
pair<int, int> f[N];

int main() {
    int c, n;
    scanf("%d %d", &c, &n);
    n *= c;
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", x + i, y + i);
        --x[i];
    }
    int r = 0;
    iota(val, val + c, 0);
    do {
        memset(f, 0x3f, n * sizeof *f);
        for(int i = 0; i < n; ++i) {
            pair<int, int> p(val[x[i]], y[i]);
            int j = lower_bound(f, f + n, p) - f;
            f[j] = p;
            if(r < j + 1) {
                r = j + 1;
            }
        }
    } while(next_permutation(val, val + c));
    printf("%d", n - r);
    return 0;
}
