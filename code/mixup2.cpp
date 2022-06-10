#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 16;
int a[N];
LL f[1 << N][N];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    for(int i = 0; i < n; ++i) {
        f[1 << i][i] = 1;
    }
    for(int t = 0; t < 1 << n; ++t) {
        for(int i = 0; i < n; ++i) {
            LL ft = f[t][i];
            if(ft == 0) continue;
            for(int j = 0; j < n; ++j) {
                if(!(t >> j & 1) && abs(a[i] - a[j]) > k) {
                    f[t | 1 << j][j] += ft;
                }
            }
        }
    }
    LL res = 0;
    for(int i = 0; i < n; ++i) {
        res += f[(1 << n) - 1][i];
    }
    printf("%lld", res);
    return 0;
}
