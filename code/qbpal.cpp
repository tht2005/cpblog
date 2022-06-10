#include <bits/stdc++.h>

using namespace std;

const int B = (int)1e9;
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
void wr(const bigint& a) {
    printf("%d", a.empty() ? 0 : a.back());
    for(int i = (int)a.size() - 2; i >= 0; --i) {
        printf("%09d", a[i]);
    }
}

const int N = 122;
char s[N];
bigint f[N][N];

int main() {
    scanf("%s", s);
    int n = strlen(s);
    for(int i = 0; i < n; ++i) {
        f[i][i].push_back(1);
        f[i][i + 1].push_back(2 + (s[i] == s[i + 1]));
    }
    for(int L = 2; L < n; ++L) {
        for(int i = 0, j = L; j < n; ++i, ++j) {
            if(s[i] == s[j]) {
                f[i][j].push_back(1);
                f[i][j] += f[i + 1][j];
                f[i][j] += f[i][j - 1];
//                f[i][j] = f[i + 1][j] + f[i][j - 1] + 1;
            }
            else {
                f[i][j] += f[i + 1][j];
                f[i][j] += f[i][j - 1];
                f[i][j] -= f[i + 1][j - 1];
//                f[i][j] = f[i + 1][j] + f[i][j - 1] - f[i + 1][j - 1];
            }
        }
    }
    wr(f[0][n - 1]);
    return 0;
}
