#include <bits/stdc++.h>

using namespace std;

const int N = 402;
const int H = 40004;

struct dt {
    int h, a, c;
    bool operator< (const dt& B) const {
        return a < B.a;
    }
} x[N];

int n;
bool f[H];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d %d %d", &x[i].h, &x[i].a, &x[i].c);
    }
    sort(x, x + n);
    f[0] = 1;
    for(int i = 0; i < n; ++i) {
        for(int j = x[i].a; j >= x[i].h; --j) {
            for(int t = x[i].c, k = j; (k -= x[i].h) >= 0 && t--; ) {
                if(f[k]) {
                    f[j] = 1;
                    break;
                }
            }
        }
    }
    for(int h = H; h--; ) {
        if(f[h]) {
            printf("%d", h);
            break;
        }
    }
    return 0;
}
