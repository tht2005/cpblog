#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1000006;
LL s[N], f[N];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    s[0] = 0;
    for(int i = 1; i <= n; ++i) {
        scanf("%lld", s + i);
        s[i] += s[i - 1];
    }
    deque<LL> d;
    if(k != 1) d.push_back(0);
    d.push_back(-s[1]);
    f[0] = 0;
    for(int i = 1; i <= n; ++i) {
        f[i] = s[i] + d.front();
        while(!d.empty() && d.back() < f[i] - s[i + 1]) {
            d.pop_back();
        }
        d.push_back(f[i] - s[i + 1]);
        if(i + 1 >= k && d.front() == ((i < k) ? 0 : f[i - k] - s[i + 1 - k])) {
            d.pop_front();
        }
    }
    printf("%lld", *max_element(f, f + 1 + n));
    return 0;
}
