#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a[100001];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    int s = a[n - 1], f = s;
    for(int i = 0; i + 1 < n; ++i) {
        s += a[i];
        if(f > s) f = s;
    }
    if(s > 0) {
        int res = (f > 0);
        for(int i = n - 2; i >= 0; --i) {
            f = min(a[i], f + a[i]);
            if(f > 0) ++res;
        }
        printf("%d", res);
    }
    else {
        putchar('0');
    }
    return 0;
}
