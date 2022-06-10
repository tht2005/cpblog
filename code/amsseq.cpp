#include <bits/stdc++.h>

using namespace std;

int f[10001];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    f[0] = 0;
    int res = 0;
    for(int i = 1, a, b; i <= n; ++i) {
        scanf("%d", &a);
        b = -1e9;
        for(int j = max(0, i - k); j < i; ++j) {
            if(b < f[j]) {
                b = f[j];
            }
        }
        f[i] = a + b;
        if(res < f[i]) {
            res = f[i];
        }
    }
    printf("%d", res);
    return 0;
}
