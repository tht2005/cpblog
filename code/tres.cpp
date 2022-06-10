#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 17;
int n, a[N];
LL f[N], pw[N];

LL calc(LL _) {
    n = 0;
    do a[n++] = _ % 10; while(_ /= 10);
    LL res = 0;
    for(int c = 1; c < 10; ++c) {
        LL val = 0;
        for(int i = n, pref = 0, cnt = 0; i--; ) {
            val += (a[i] - (c < a[i])) * ((pref + cnt * cnt) * pw[i] + f[i]);
            if(c < a[i]) {
                for(int j = i; j > 0; --j) {
                    val += 9 * (pw[j - 1] * (pref + (cnt + i + 1 - j) * (cnt + i + 1 - j)) + f[j - 1]);
                }
                val += pref + (cnt + i + 1) * (cnt + i + 1);
            }
            if(a[i] == c) {
                ++cnt;
            }
            else if(cnt) {
                pref += cnt * cnt;
                cnt = 0;
            }
        }
        res += val * c;
    }
    return res;
}

int main() {
    f[0] = 0;
    pw[0] = 1;
    for(int i = 1; i < N; ++i) {
        f[i] = 9 * f[i - 1] + i * i;
        for(int j = 1; j < i; ++j) {
            f[i] += 9 * (pw[i - 1 - j] * j * j + f[i - 1 - j]);
        }
        pw[i] = pw[i - 1] * 10;
    }
    LL l, r;
    scanf("%lld %lld", &l, &r);
    printf("%lld", calc(r + 1) - calc(l));
    return 0;
}

