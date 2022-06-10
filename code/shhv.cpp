#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int n, tmp, a[12];
bool used[12];
LL k, res, f[12];
char s[50], *t;

int main() {
    scanf("%[^\n]s", s);
    t = s;
    n = 0;
    while(sscanf(t, "%d%n", a + n, &tmp) == 1) {
        --a[n];
        ++n;
        t += tmp;
    }
    f[0] = 1;
    for(int i = 1; i < n; ++i) {
        f[i] = f[i - 1] * i;
    }
    res = 1;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < a[i]; ++j) {
            if(used[j]) continue;
            res += f[n - 1 - i];
        }
        used[a[i]] = 1;
    }
    printf("%lld\n", res);
    scanf("%lld", &k);
    for(int i = 0; i < n; ++i) {
        int j = 0;
        while(1) {
            if(used[j]) {
                if(k <= f[n - 1 - i]) {
                    break;
                }
                k -= f[n - 1 - i];
            }
            ++j;
        }
        used[j] = 0;
        printf("%d ", j + 1);
    }
    return 0;
}
