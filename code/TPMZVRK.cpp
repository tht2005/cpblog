#include <bits/stdc++.h>

using namespace std;

#define md 15111992
#define N 205

int x[N], y[N];
char a[N], b[N];

int main() {
    scanf("%s %s", a, b);
    int n = strlen(b);
    for(int i = strlen(a), ptr = n; ptr--; )
        a[ptr] = i ? a[--i] : '0';
    for(int i = 0; i < n; ++i) {
        x[i + 1] = (2 * x[i] + a[i] - '0') % md;
        y[i + 1] = (2 * y[i] + b[i] - '0') % md;
    }
    int res = 0;
    for(int i = n, pw = 1; i--; ) {
        res = (res + (int64_t)pw * ((y[i] - x[i] + b[i] - a[i] + md) % md) % md) % md;
        pw = (pw + pw) % md;
    }
    printf("%d", res);
    return 0;
}
