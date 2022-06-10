#include <bits/stdc++.h>

using namespace std;

const int md = (int)1e9 + 7;
void add(int& a, int b) {
    a += b;
    if(a >= md) a -= md;
    if(a < 0) a += md;
}

const int N = 1001;
const int S = 10001;

int a[N], f[S], g[S];

int main() {
    int n, s;
    scanf("%d %d", &n, &s);
    f[0] = 1;
    for(int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        for(int j = s; j >= a[i]; --j) {
            add(f[j], f[j - a[i]]);
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= s - a[i]; ++j) {
            g[j] = f[j];
            if(j >= a[i]) {
                add(g[j], -g[j - a[i]]);
            }
        }
        if(i) {
            putchar(' ');
        }
        printf("%d", (s < a[i]) ? 0 : g[s - a[i]]);
    }
    return 0;
}
