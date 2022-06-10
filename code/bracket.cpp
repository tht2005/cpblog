#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 61;

int n, k;
LL res, f[N][N][2];
char s[N];

int main() {
    scanf("%d %d %s", &n, &k, s);
    f[n][0][1] = 1;
    for(int i = n; i--; ) {
        for(int j = 0; j <= k; ++j) {
            for(int t = 0; t < 2; ++t) {
                if(j != 0) f[i][j][t] += f[i + 1][j - 1][t];
                if(j != k) f[i][j][t] += f[i + 1][j + 1][t || (j + 1 == k)];
            }
        }
    }
    res = 1;
    for(int i = 0, j = 0, t = 0; i < n; ++i) {
        if(s[i] == '(') {
            if((++j) == k) {
                t = 1;
            }
        }
        else {
            if(j != k) {
                res += f[i + 1][j + 1][t || (j + 1 == k)];
            }
            --j;
        }
    }
    printf("%lld\n%lld", f[0][0][0], res);
    return 0;
}
