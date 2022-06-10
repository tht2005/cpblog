#include <bits/stdc++.h>

using namespace std;

const int N = 1503;
int a[N], b[N], f[N];

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        int m, n;
        scanf("%d %d", &m, &n);
        for(int i = 0; i < m; ++i) {
            scanf("%d", a + i);
        }
        for(int i = 0; i < n; ++i) {
            scanf("%d", b + i);
        }
        memset(f, 0, n * sizeof *f);
        for(int i = 0; i < m; ++i) {
            int val = 0;
            for(int j = 0, g; j < n; ++j) {
                g = f[j];
                if(a[i] == b[j]) {
                    f[j] = max(f[j], val + 1);
                }
                if(2 * b[j] <= a[i]) {
                    val = max(val, g);
                }
            }
        }
        printf("%d\n", *max_element(f, f + n));
    }
    return 0;
}
