#include <bits/stdc++.h>

using namespace std;

#define H 30

int f[H + 1][2], pw[H + 1];

int main() {
    int n, x, k;
    scanf("%d %d %d", &n, &x, &k);
    f[0][0] = 0;
    f[0][1] = 1;
    for(int i = 1; i <= H; ++i) {
        f[i][1] = f[i - 1][0] + f[i - 1][1];
        f[i][0] = f[i][1];
        if(i > k) f[i][0] -= f[i - 1 - k][1];
    }
    int ord = 0;
    for(int i = n, cnt = 0; i--; ) {
        int val = 0;
        for(int j = i; j >= 0 && j > i + cnt - k; --j) {
            val += f[j][1];
        }
        ord <<= 1;
        if(x > val) {
            x -= val;
            ord |= 1;
            cnt = 0;
        }
        else {
            ++cnt;
        }
    }
    pw[0] = 1;
    for(int i = 1; i <= H; ++i) {
        pw[i] = min((long long)2e9, 10LL * pw[i - 1]);
    }
    for(int i = 0; i < n; ++i) {
        int j = 0;
        for(; ord >= pw[n - 1 - i]; ++j) {
            ord -= pw[n - 1 - i];
        }
        if(i) putchar(' ');
        printf("%d", j);
    }
    return 0;
}
