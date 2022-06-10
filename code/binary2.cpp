#include <bits/stdc++.h>

using namespace std;

int n, k, f[1000001];
long long s;

int main() {
    scanf("%d %d", &n, &k);
    f[0] = s = 2;
    for(int i = 1; i <= n; ++i) {
        f[i] = s % (int)1e9;
        s += f[i];
        if(i >= k) s -= f[i - k];
    }
    printf("%d", f[n]);
    return 0;
}
