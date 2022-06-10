#include <bits/stdc++.h>

using namespace std;

const int N = 300005;
int x[N], y[N];

int main() {
    int _, a, b;
    scanf("%d %d %d", &_, &a, &b);
    int n = 0, m = 0;
    while(_--) {
        int d, k;
        scanf("%d %d", &d, &k);
        if(k == 1) {
            x[n++] = d;
        }
        else {
            y[m++] = d;
        }
    }
    sort(x, x + n);
    sort(y, y + m);
    int i = 0, j = 0, res = 2e9;
    while(i < n || j < m) {
        if(i < n && (j == m || x[i] < y[j])) {
            ++i;
        }
        else {
            ++j;
        }
        if(i >= a && j >= b) {
            res = min(res, max(x[i - 1], y[j - 1]) - min(x[i - a], y[j - b]));
        }
    }
    printf("%d", (res == 2e9) ? -1 : res);
    return 0;
}