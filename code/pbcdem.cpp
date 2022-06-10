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
void print(const bigint& a) {
    printf("%d", a.empty() ? 0 : a.back());
    for(int i = (int)a.size() - 2; i >= 0; --i) {
        printf("%09d", a[i]);
    }
}

const int N = 90;
const int S = 4001;

bigint f[S][N];

int main() {
    int n;
    scanf("%d", &n);
    f[0][0].push_back(1);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j < N && j <= i; ++j) {
            f[i][j] = f[i - j][j];
            f[i][j] += f[i - j][j - 1];
        }
    }
    bigint res;
    for(int i = 2; i < N; ++i) {
        res += f[n][i];
    }
    print(res);
    return 0;
}
