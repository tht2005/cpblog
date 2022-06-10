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

bigint f[2], r[1001];

int main() {
    bigint cnt(1, 1);
    f[1].push_back(1);
    for(int i = 1; i < 1000; ++i) {
        f[0].swap(f[1]);
        f[1] += cnt;
        r[i + 1] = f[0];
        cnt += cnt;
    }
    for(int n; scanf("%d", &n) == 1;) {
        print(r[n]);
        putchar('\n');
    }
    return 0;
}

