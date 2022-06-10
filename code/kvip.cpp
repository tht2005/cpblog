#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL INF = numeric_limits<LL>::max() / 2;

const int N = 1003;

int c[N][N];
LL f[N], suf[N];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf("%d", &c[i][j]);
        }
    }
    suf[n] = 0;
    for(int i = n; i--; ) {
        suf[i] = suf[i + 1] + c[i][i];
    }
    f[0] = 0;
    for(int i = 1; i < n; ++i) {
        f[i] = -INF;
    }
    LL res = -INF;
    for(int i = 0; i < n; ++i) {
        LL s = 0;
        for(int j = i + 1; j < n; ++j) {
            f[j] = max(f[j], f[i] + s + c[i][j]);
            s += c[j][j];
        }
        res = max(res, f[i] + c[i][0] + suf[i + 1]);
    }
    printf("%lld", res);
    return 0;
}
