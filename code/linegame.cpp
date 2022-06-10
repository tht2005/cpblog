#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main() {
    LL f = numeric_limits<LL>::min() / 2, g = 0;
    int n;
    scanf("%d", &n);
    for(int a; n--; ) {
        scanf("%d", &a);
        tie(f, g) = make_tuple(max(f, g + a), max(g, f - a));
    }
    printf("%lld", max(f, g));
    return 0;
}
