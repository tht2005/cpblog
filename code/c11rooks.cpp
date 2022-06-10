#include <bits/stdc++.h>

using namespace std;

const int N = 302;
int a[N][N], r[N], c[N];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf("%d", a[i] + j);
            r[i] += a[i][j];
            c[j] += a[i][j];
        }
    }
    int res = 0;
    for(int i = 0; i < n; ++i) {
        int mx = -1e9;
        for(int j = 0; j < n; ++j) {
            if(j) {
                res = max(res, r[i] + mx + c[j] - 2 * a[i][j]);
            }
            mx = max(mx, c[j] - 2 * a[i][j]);
        }
        mx = -1e9;
        for(int j = 0; j < n; ++j) {
            if(j) {
                res = max(res, c[i] + mx + r[j] - 2 * a[j][i]);
            }
            mx = max(mx, r[j] - 2 * a[j][i]);
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i != j) {
                int mx = -1e9;
                for(int k = 0; k < n; ++k) {
                    if(k) {
                        res = max(res, r[i] + r[j] + mx + c[k] - 2 * a[i][k] - a[j][k]);
                    }
                    mx = max(mx, c[k] - a[i][k] - 2 * a[j][k]);
                }
            }
        }
    }
    printf("%d", res);
    return 0;
}
