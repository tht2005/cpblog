#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 100005;

LL n, m;

struct sub1 {
    sub1() {
        int x = 64 - __builtin_clzll(n);
        printf("%d", x - (n != (1LL << x) - 1));
    }
};
struct sub2 {
    sub2() {
        int x = 64 - __builtin_clzll(n), a = 0, b = 0;
        for(int i = x; i--; ) {
            if(m >> i & 1) {
                ++a;
            }
            else {
                ++b;
            }
        }
        printf("%lld", ((long long)(a + 1) << b) - 1);
    }
};
struct sub3 {
    int f[N], a[N];
    sub3() {
        for(int i = 0; i < n; ++i) {
            scanf("%d", a + i);
            a[i] &= m;
        }
        sort(a, a + n);
        int res = 0;
        for(int i = 0; i < n; ++i) {
            f[i] = 1;
            for(int j = 0; j < i; ++j) {
                if((a[i] | a[j]) == a[i] && f[i] < f[j] + 1) {
                    f[i] = f[j] + 1;
                }
            }
            if(res < f[i]) {
                res = f[i];
            }
        }
        printf("%d", res);
    }
};
int pos[20] = { 29, 28, 27, 26, 24, 23, 22, 20, 18, 17, 16, 15, 11, 10, 8, 6, 4, 2, 1, 0 };
struct sub4 {
    int f[1 << 20];
    sub4() {
        memset(f, 0, sizeof(f));
        for(int i = 0, x, y; i < n; ++i) {
            scanf("%d", &x);
            y = 0;
            for(int j = 20; j--; ) {
                if(x >> pos[j] & 1) {
                    y |= 1 << j;
                }
            }
            ++f[y];
        }
        for(int t = 0; t < 1 << 20; ++t) {
            int v = 0;
            for(int i = 0; i < 20; ++i) {
                if(t >> i & 1) {
                    v = max(v, f[t ^ (1 << i)]);
                }
            }
            f[t] += v;
        }
        printf("%d", f[(1 << 20) - 1]);
    }
};

int main() {
    scanf("%lld %lld", &n, &m);
    if(n > 100000) {
        if(m == (1LL << 60) - 1) {
            delete new sub1;
        }
        else {
            delete new sub2;
        }
    }
    else {
        if(n > 5000) {
            delete new sub4;
        }
        else {
            delete new sub3;
        }
    }
    return 0;
}
