#include <bits/stdc++.h>

using namespace std;

const int B = (int)1e9;
typedef vector<int> bigint;

void print(const bigint& a) {
    printf("%d", a.empty() ? 0 : a.back());
    for(int i = (int)a.size() - 2; i >= 0; --i) {
        printf("%09d", a[i]);
    }
}

void operator+= (bigint& a, const bigint& b) {
    int carry = 0;
    for(size_t i = 0; i < max(a.size(), b.size()) || carry; ++i) {
        if(i == a.size()) {
            a.push_back(0);
        }
        a[i] += carry + (i < b.size() ? b[i] : 0);
        carry = (a[i] >= B);
        if(carry) a[i] -= B;
    }
}
void operator-= (bigint& a, const bigint& b) {
    int carry = 0;
    for(size_t i = 0; i < b.size() || carry; ++i) {
        a[i] -= carry + (i < b.size() ? b[i] : 0);
        carry = (a[i] < 0);
        if(carry) a[i] += B;
    }
    while(a.size() > 1 && a.back() == 0) {
        a.pop_back();
    }
}

const int N = 10004;
bigint f[N], g[N];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    g[0].push_back(1);
    for(int i = 1; i <= n; ++i) {
        g[i] = g[i - 1];
        g[i] += f[i - 1];
        f[i] = g[i];
        if(i >= k) f[i] -= g[i - k];
    }
    bigint res(1, 1);
    for(int i = 0; i < n; ++i) {
        res += res;
    }
    res -= f[n];
    res -= g[n];
    print(res);
    return 0;
}
