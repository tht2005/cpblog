#include <bits/stdc++.h>

using namespace std;

const int N = 50004;
int n, p, v, r, s[N];
bool d[N];

int main() {
    scanf("%d %d", &n, &p);
    ++n;
    s[0] = 0;
    for(int i = 1; i < n; ++i) {
        scanf("%d", s + i);
        s[i] += s[i - 1];
    }
    d[0] = 1;
    v = 0;
    for(int i = 1; i < n; ++i) {
        if(s[i] < v) {
            v = s[i];
            d[i] = 1;
        }
    }
    r = -1;
    for(int i = n, j = n - 1; i--; ) {
        if(d[i]) {
            for(; j > i; --j) {
                if(s[j] - s[i] >= p) {
                    r = max(r, j - i);
                    break;
                }
            }
        }
    }
    printf("%d", r);
    return 0;
}
