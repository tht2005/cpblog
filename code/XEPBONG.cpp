#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long LL;

const int B = 1000000000;
typedef vector<int> bigint;

void print(const bigint& a) {
    printf("%d", a.empty() ? 0 : a.back());
    for(int i = (int)a.size() - 2; i >= 0; --i) {
        printf("%09d", a[i]);
    }
}
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
        carry = cur / B;
        a[i] = cur % B;
    }
    while(a.size() > 1 && a.back() == 0) {
        a.pop_back();
    }
}

const int N = 51;
bigint f[N][N], r[N], tmp;

int main() {
    f[0][0].push_back(1);
    for(int i = 1; i < N; ++i) {
        for(int j = 1; j <= i; ++j) {
            tmp = f[i - 1][j];
            tmp *= j;
            f[i][j] = f[i - 1][j - 1];
            f[i][j] += tmp;
            r[i] += f[i][j];
        }
    }
    int n;
    while(scanf("%d", &n), n) {
        printf("%d ", n);
        print(r[n]);
        putchar('\n');
    }
    return 0;
}
