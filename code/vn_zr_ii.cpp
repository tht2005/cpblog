#include <bits/stdc++.h>

using namespace std;

#define H 31
long long f[H + 1];

int main() {
    int n, k;
    while(~scanf("%d %d", &n, &k)) {
        f[0] = 0;
        for(int i = 1; i <= H; ++i) {
            f[i] = f[i - 1];
            for(int j = 1; j < i; ++j) {
                f[i] += (1LL << max(0, i - j - 2)) * ((j - 1) / k + 1) + f[i - j - 1];
            }
        }
        long long res = 0;
        int i = 31 - __builtin_clz(n);
        for(int j = 1; j <= i; ++j) {
            res += f[j];
        }
        int cnt = 0, pref = 0;
        while(i--) {
            if(n >> i & 1) {
                for(int j = 0; j <= i; ++j) {
                    res += f[j] + (1LL << max(0, j - 1)) * (pref + (cnt + i - j) / k + 1);
                }
                if(cnt) {
                    pref += (cnt - 1) / k + 1;
                    cnt = 0;
                }
            }
            else {
                ++cnt;
            }
        }
        if(cnt) {
            pref += (cnt - 1) / k + 1;
        }
        res += pref;
        printf("%lld\n", res);
    }
    return 0;
}
