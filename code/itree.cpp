#include <bits/stdc++.h>

using namespace std;

const int N = 1003;
int p[N], w[N], f[N];
bool leaf[N];

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        int n;
        scanf("%d", &n);
        memset(leaf, 1, n * sizeof *leaf);
        for(int i = 1; i < n; ++i) {
            scanf("%d %d", p + i, w + i);
            --p[i];
            leaf[p[i]] = 0;
        }
        memset(f, 0, n * sizeof *f);
        for(int i = n; i --> 1; ) {
            if(leaf[i]) {
                f[p[i]] += w[i];
            }
            else {
                f[p[i]] += min(f[i], w[i]);
            }
        }
        printf("%d.00\n", f[0]);
    }
    return 0;
}
