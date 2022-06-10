#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 61;

int a[N], b[N], v[N];
LL nCr[N][N];

int main() {
    for(int i = 0; i < N; ++i) {
        nCr[i][0] = nCr[i][i] = 1;
        for(int j = 1, k = i >> 1; j <= k; ++j) {
            nCr[i][j] = nCr[i][i - j] = nCr[i - 1][j] + nCr[i - 1][j - 1];
        }
    }
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        v[i] = a[i];
    }
    sort(v, v + n);
    for(int i = 0; i < n; ++i) {
        a[i] = lower_bound(v, v + n, a[i]) - v;
    }
    LL m;
    scanf("%lld", &m);
    for(int i = 0; i < k; ++i) {
        b[i] = 0;
        for(int& j = b[i];; ++j) {
            int x = 0;
            for(int y = 0; y <= i; ++y) {
                while(x < n && a[x] != b[y]) {
                    ++x;
                }
                ++x;
            }
            if(x > n) {
                continue;
            }
            if(m <= nCr[n - x][k - 1 - i]) {
                break;
            }
            m -= nCr[n - x][k - 1 - i];
        }
        if(i) putchar(' ');
        printf("%d", v[b[i]]);
    }
    LL res = 1;
    for(int i = 0, x = 0; i < k; ++i) {
        scanf("%d", b + i);
        b[i] = lower_bound(v, v + n, b[i]) - v;
        for(int j = b[i]; j--; ) {
            int y = x;
            while(y < n && a[y] != j) {
                ++y;
            }
            if(y < n) {
                res += nCr[n - 1 - y][k - 1 - i];
            }
        }
        while(a[x] != b[i]) {
            ++x;
        }
        ++x;
    }
    printf("\n%lld", res);
    return 0;
}
