#include <bits/stdc++.h>

using namespace std;

const int B = 1e9;
typedef vector<int> bigint;
void operator+= (bigint& a, const bigint& b) {
    int carry = 0;
    for(size_t i = 0; i < a.size() || i < b.size() || carry; ++i) {
        if(i == a.size()) {
            a.push_back(0);
        }
        a[i] += carry + (i < b.size() ? b[i] : 0);
        carry = (a[i] >= B);
        if(carry) a[i] -= B;
    }
}
void operator*= (bigint& a, int b) {
    int carry = 0;
    for(size_t i = 0; i < a.size() || carry; ++i) {
        if(i == a.size()) {
            a.push_back(0);
        }
        long long cur = carry + (long long)a[i] * b;
        a[i] = cur % B;
        carry = cur / B;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    bigint f(1, 1), g(1, 1);
    for(int i = 1; i < n; ++i) {
        f *= i;
        f += g;
        f.swap(g);
    }
    printf("%d", g.empty() ? 0 : g.back());
    for(int i = (int)g.size() - 2; i >= 0; --i) {
        printf("%09d", g[i]);
    }
    return 0;
}
