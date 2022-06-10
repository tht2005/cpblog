#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main() {
    LL l, r;
    scanf("%lld %lld", &l, &r);
    --l;
    LL res = 0, pw = 1;
    do {
        int x = l & 1, y = r & 1;
        l >>= 1;
        r >>= 1;
        res += pw * (r - l + y - x);
        pw <<= 1;
    } while(r);
    printf("%lld", res);
    return 0;
}
