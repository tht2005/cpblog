#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int f[1003], g[1003];
    memset(f, 0x3f, (n + 1) * sizeof *f);
    f[0] = 0;
    for(int i = 0; i < n; ++i) {
        int p;
        scanf("%d", &p);
        memcpy(g, f, (n + 1) * sizeof *f);
        memset(f, 0x3f, (n + 1) * sizeof *f);
        for(int j = 0; j <= i; ++j) {
            int ft = g[j];
            if(ft == 0x3f3f3f3f) continue;
            f[j + (p > 100)] = min(f[j + (p > 100)], ft + p);
            if(j) f[j - 1] = min(f[j - 1], ft);
        }
    }
    printf("%d", f[0]);
    return 0;
}
