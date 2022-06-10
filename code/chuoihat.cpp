#include <bits/stdc++.h>

using namespace std;

const int B = (int)1e9;
typedef vector<int> bigint;

void read(bigint& a) {
    static char s[1000];
    scanf("%s", s);
    a.clear();
    for(int i = strlen(s); i > 0; i -= 9) {
        s[i] = 0;
        a.push_back(atoi(i < 9 ? s : s + i - 9));
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
    for(size_t i = 0; i < a.size() || carry; ++i) {
        a[i] -= carry + (i < b.size() ? b[i] : 0);
        carry = (a[i] < 0);
        if(carry) a[i] += B;
    }
    while(a.size() > 1 && a.back() == 0) {
        a.pop_back();
    }
}

bool operator< (bigint& a, bigint& b) {
    while(a.size() > 1 && a.back() == 0) {
        a.pop_back();
    }
    while(b.size() > 1 && b.back() == 0) {
        b.pop_back();
    }
    if(a.size() != b.size()) return a.size() < b.size();
    for(int i = a.size(); i--; ) {
        if(a[i] != b[i]) {
            return a[i] < b[i];
        }
    }
    return 0;
}

bigint f[255][505];

int main() {
    int n;
    scanf("%d", &n);
    bigint k;
    read(k);
    for(int i = 2 * n; i > 0; --i) {
        f[n][i].push_back(1);
    }
    for(int i = n - 1; i > 0; --i) {
        for(int j = 2 * i; j > 0; --j) {
            for(int k = 2 * i + 2; k > j; --k) {
                f[i][j] += f[i + 1][k];
            }
        }
    }
    for(int i = 1, j = 1; i <= n; ++i) {
        for(; f[i][j] < k; ++j) {
            k -= f[i][j];
        }
        if(i > 1) putchar(' ');
        printf("%d", j++);
    }
    return 0;
}
