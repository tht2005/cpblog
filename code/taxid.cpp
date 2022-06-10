#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define M 71
#define B 36
#define L 12

int a[L];
LL pw[L], f[L];

int main() {
    LL n, q;
    int m, p;
    scanf("%lld %d %d %lld", &n, &m, &p, &q);
    int k = (m - 1) / 2, c[M];
    c[0] = 0;
    for(int i = 1; i <= k; ++i) {
        scanf("%d", c + i);
    }
    c[k + 1] = B;
    int l = 0;
    do {
        a[l++] = n % B;
    } while(n /= B);
    int s = c[(p + 1) / 2 - 1], t = c[(p + 1) / 2];
    pw[0] = 1;
    f[0] = 0;
    for(int i = 1; i <= l; ++i) {
        pw[i] = pw[i - 1] * t;
        f[i] = f[i - 1] * s + pw[i - 1] * (t - s);
    }
    if(p & 1 ^ 1) {
        LL cnt = 0;
        bool pref = 0;
        for(int i = l; i--; ) {
            for(int j = 0; j < a[i] && j < t; ++j) {
                if(pref || j >= s) {
                    cnt += pw[i];
                }
                else {
                    cnt += f[i];
                }
            }
            if(a[i] >= s) {
                pref = 1;
            }
            if(a[i] >= t) {
                pref = 0;
                break;
            }
        }
        if(pref) {
            ++cnt;
        }
        if(s == 0) {
            --cnt;
        }
        q = cnt + 1 - q;
    }
    for(int i = l, pref = 0, z = 0, j; i--; ) {
        for(j = 0;; ++j) {
            LL val = (pref || j >= s) ? pw[i] - (z == 0 && j == 0) : f[i];
            if(q <= val) {
                break;
            }
            q -= val;
        }
        if(j >= s) {
            pref = 1;
        }
        if(j) {
            z = 1;
        }
        if(z) {
            putchar((j < 10) ? (j + '0') : (j - 10 + 'a'));
        }
    }
    return 0;
}
