#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 3003;
LL a[N][N];

int main() {
    int n;
    scanf("%d", &n);
    for(int s = 0; s < n; ++s) {
        for(int i = 0; i < n && i <= s; ++i) {
            scanf("%lld", &a[s - i][i]);
        }
    }
    LL res = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 1; j < n - i; ++j) {
            a[i][j] += a[i][j - 1];
        }
        for(int j = n - i; j--; ) {
            if(i) {
                a[i][j] += a[i - 1][j];
            }
            if(j + 1 != n - i && a[i][j] < a[i][j + 1]) {
                a[i][j] = a[i][j + 1];
            }
        }
        if(res < a[i][0]) {
            res = a[i][0];
        }
    }
    printf("%lld", res);
    return 0;
}
