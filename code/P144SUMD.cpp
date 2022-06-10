#include <bits/stdc++.h>

using namespace std;

const int N = 4003;
const int V = 1000006;

int a[N], f[N][N], mx[V];

int main() {
    int n;
    scanf("%d", &n);
    if(n == 1) {
        putchar('1');
    }
    else {
        for(int i = 0; i < n; ++i) {
            scanf("%d", a + i);
        }
        for(int i = 0; i < n; ++i) {
            f[i][i] = 1;
            for(int j = i + 1; j < n; ++j) {
                f[i][j] = 2;
            }
        }
        memset(mx, 0xff, sizeof(mx));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j <= i; ++j) {
                mx[a[j]] = max(mx[a[j]], f[j][i]);
            }
            for(int j = i + 1; j < n; ++j) {
                f[i][j] = max(f[i][j], mx[a[j]] + 1);
            }
            for(int j = 0; j <= i; ++j) {
                mx[a[j]] = -1;
            }
        }
        int res = 2;
        for(int i = 0; i < n; ++i) {
            for(int j = i; j < n; ++j) {
                if(res < f[i][j]) {
                    res = f[i][j];
                }
            }
        }
        printf("%d", res);
    }
    return 0;
}
