#include <bits/stdc++.h>

using namespace std;

struct dt {
    int n, s, k;
    bool operator< (const dt& b) const {
        if(n != b.n) return n < b.n;
        if(s != b.s) return s < b.s;
        return k < b.k;
    }
};

dt f[10004];
int dn[10004], ds[10004];

int main() {
    int e;
    scanf("%d", &e);
    for(int i = 1; i <= e; ++i) {
        for(int j = sqrt(i);; --j) {
            if(i % j == 0) {
                dn[i] = j + (i / j);
                ds[i] = j;
                break;
            }
        }
    }
    memset(f, 0x3f, sizeof(f));
    f[0].n = f[0].s = f[0].k = 0;
    for(int i = 0; i < e; ++i) {
        for(int j = 1; i + j <= e; ++j) {
            dt tmp(f[i]);
            tmp.n += dn[j];
            tmp.s += ds[j];
            ++tmp.k;
            if(tmp < f[i + j]) {
                f[i + j] = tmp;
            }
        }
    }
    printf("%d %d %d", f[e].n, f[e].s, f[e].k);
    return 0;
}
