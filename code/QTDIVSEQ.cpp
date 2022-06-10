#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int md = (int)1e9 + 7;
#define mul(a, b) ((long long)(a) * (b) % md)
int binpow(int a, int n) {
    int ret = 1;
    for(; n > 0; n >>= 1) {
        if(n & 1) ret = mul(ret, a);
        a = mul(a, a);
    }
    return ret;
}
int nCr(int n, int r) {
    if(n < r) return 0;
    int a = 1, b = 1;
    for(int i = n - r + 1; i <= n; ++i) {
        a = mul(a, i);
    }
    for(int i = 2; i <= r; ++i) {
        b = mul(b, i);
    }
    return mul(a, binpow(b, md - 2));
}

const int N = 1000006;
int f[N];
LL s[N];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    s[0] = 0;
    for(int i = 1; i <= n; ++i) {
        scanf("%lld", s + i);
        s[i] += s[i - 1];
    }
    if(s[n] == 0) {
        int z = 0;
        for(int i = 1; i < n; ++i) {
            if(s[i] == 0) {
                ++z;
            }
        }
        printf("%d", nCr(z, k - 1));
    }
    else if(s[n] % k == 0) {
        LL a = s[n] / k;
        f[0] = 1;
        for(int i = 1, j; i <= n; ++i) {
            if(s[i] % a == 0 && (j = s[i] / a) > 0) {
                f[j] += f[j - 1];
                if(f[j] >= md) {
                    f[j] -= md;
                }
            }
        }
        printf("%d", f[k - 1]);
    }
    else {
        putchar('0');
    }
    return 0;
}
