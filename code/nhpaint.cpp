#include <bits/stdc++.h>

using namespace std;

void ckmin(int& a, int b) {
    if(a > b) {
        a = b;
    }
}

const int M = 10001;
const int N = 16;

bitset<M> tmp, a[N];
int cnt[N], c[N][N], f[1 << N][N];

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            char c;
            scanf(" %c", &c);
            if(c == '1') {
                a[j].set(i);
                ++cnt[j];
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            tmp = a[i];
            tmp ^= a[j];
            c[i][j] = tmp.count();
        }
    }
    memset(f, 0x3f, sizeof(f));
    for(int i = 0; i < n; ++i) {
        f[1 << i][i] = cnt[i];
    }
    for(int t = 0; t < 1 << n; ++t) {
        for(int i = 0; i < n; ++i) {
            int ft = f[t][i];
            if(ft == 0x3f3f3f3f) continue;
            for(int j = 0; j < n; ++j) {
                if(t >> j & 1) continue;
                ckmin(f[t | (1 << j)][j], ft + c[i][j]);
            }
            for(int j = i - 1; j <= i + 1; j += 2) {
                if(j < 0 || j >= n || (t >> j & 1)) continue;
                ckmin(f[t | (1 << j)][j], ft + cnt[j]);
            }
        }
    }
    printf("%d", *min_element(f[(1 << n) - 1], f[(1 << n) - 1] + n));
    return 0;
}
