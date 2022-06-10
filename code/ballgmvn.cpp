#include <bits/stdc++.h>

using namespace std;

struct dt {
    int n, d, i;
    bool operator== (const dt& b) const {
        return (long long)n * b.d == (long long)b.n * d;
    }
    bool operator< (const dt& b) const {
        return (long long)n * b.d < (long long)b.n * d;
    }
};

const int N = 2003;
int x[N], y[N], pos[2];
dt a[N * N];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n << 1; ++i) {
        scanf("%d %d", x + i, y + i);
    }
    for(int i = n << 1; i--; ) {
        int m = 0;
        for(int j = n << 1; j--; ) {
            if(i != j) {
                a[m].n = y[j] - y[i];
                a[m].d = x[j] - x[i];
                a[m].i = j;
                ++m;
            }
        }
        sort(a, a + m);
        for(int l = 0, r = 0; r < m; l = r) {
            pos[0] = pos[1] = -1;
            while(r < m && a[l] == a[r]) {
                if(~pos[a[r].i >= n]) {
                    printf("%d %d %d", i + 1, pos[a[r].i >= n] + 1, a[r].i + 1);
                    return 0;
                }
                if((i < n) != (a[r].i < n) && ~pos[a[r].i < n]) {
                    printf("%d %d %d", i + 1, pos[a[r].i < n] + 1, a[r].i + 1);
                    return 0;
                }
                pos[a[r].i < n] = a[r].i;
                ++r;
            }
        }
    }
    puts("-1");
    return 0;
}
