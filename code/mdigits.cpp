#include <bits/stdc++.h>

using namespace std;

const int N = 10;

int f[N], pw[N];
char a[N], b[N];

int main() {
    f[0] = 0;
    pw[0] = 1;
    for(int i = 1; i < N; ++i) {
        f[i] = i * pw[i - 1];
        pw[i] = pw[i - 1] * 10;
    }
    int l, r;
    while(scanf("%d %d", &l, &r), l && r) {
        if(l > r) swap(l, r);
        ++r;
        sprintf(a, "%d", l);
        sprintf(b, "%d", r);
        int n = strlen(a), m = strlen(b);
        for(int c = 0; c < 10; ++c) {
            int cnt = 0;
            if(c) {
                cnt += f[m - 1] - f[n - 1];
            }
            else {
                for(int i = 1; i < m; ++i) {
                    cnt += 9 * f[i - 1];
                }
                for(int i = 1; i < n; ++i) {
                    cnt -= 9 * f[i - 1];
                }
            }
            for(int i = 0, pref = 0; i < m; ++i) {
                for(int j = (i == 0); j < b[i] - '0'; ++j) {
                    cnt += (pref + (j == c)) * pw[m - 1 - i] + f[m - 1 - i];
                }
                if(b[i] - '0' == c) {
                    ++pref;
                }
            }
            for(int i = 0, pref = 0; i < n; ++i) {
                for(int j = (i == 0); j < a[i] - '0'; ++j) {
                    cnt -= (pref + (j == c)) * pw[n - 1 - i] + f[n - 1 - i];
                }
                if(a[i] - '0' == c) {
                    ++pref;
                }
            }
            if(c) putchar(' ');
            printf("%d", cnt);
        }
        putchar('\n');
    }
    return 0;
}
