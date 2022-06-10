#include <bits/stdc++.h>

using namespace std;

const int N = 10004;
const int M = 100005;
const int maxr = 100;

int n, m, r[N], dp[N], f[M], mem[maxr + 1];
char s[M];

int calc(int r) {
    if(mem[r]) return mem[r];
    deque<int> d;
    d.push_back(0);
    f[m + 1] = 0;
    for(int i = m; i >= 0; --i) {
        f[i] = (s[i] == '0') ? (d.front() + 1) : 1000000000;
        while(!d.empty() && f[i] < d.back()) {
            d.pop_back();
        }
        d.push_back(f[i]);
        if(i + r <= m + 1 && d.front() == f[i + r]) {
            d.pop_front();
        }
    }
    return mem[r] = f[0];
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%d", r + i);
    }
    s[0] = '0';
    scanf("%s", s + 1);
    for(int i = 0; i < n; ++i) {
        r[i] = calc(r[i]);
    }
    sort(r, r + n);
    dp[0] = r[0];
    if(n > 1) dp[1] = r[1];
    for(int i = 2; i < n; ++i) {
        dp[i] = min(dp[i - 1] + r[0] + r[i], dp[i - 2] + r[0] + r[i] + 2 * r[1]);
    }
    printf("%d", dp[n - 1]);
    return 0;
}
