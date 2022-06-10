#include <bits/stdc++.h>

using namespace std;

#define H 32
int k, B, a[H + 1], nCr[H][H];

int calc(int x) {
    int n = 0;
    do {
        a[n++] = x % B;
    } while(x /= B);
    int res = 0, cnt = 0;
    for(int i = n; (i--); ) {
        if(a[i] > 0) {
            if(cnt <= k) {
                res += nCr[i][k - cnt];
            }
        }
        if(a[i] > 1) {
            if(cnt < k) {
                res += nCr[i][k - 1 - cnt];
            }
            return res;
        }
        if(a[i] == 1) {
            ++cnt;
        }
    }
    if(cnt == k) {
        ++res;
    }
    return res;
}

int main() {
    for(int i = 0; i < H; ++i) {
        nCr[i][0] = nCr[i][i] = 1;
        for(int j = 1, _ = i >> 1; j <= _; ++j) {
            nCr[i][j] = nCr[i][i - j] = nCr[i - 1][j] + nCr[i - 1][j - 1];
        }
    }
    int l, r;
    scanf("%d %d %d %d", &l, &r, &k, &B);
    printf("%d", calc(r) - calc(l - 1));
    return 0;
}
