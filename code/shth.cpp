#include <bits/stdc++.h>

using namespace std;

const int B = (int)1e9;
typedef vector<int> bigint;

void rd(bigint& a) {
    static char s[1000];
    scanf("%s", s);
    a.clear();
    for(int i = strlen(s); i > 0; i -= 9) {
        s[i] = 0;
        a.push_back(atoi(i < 9 ? s : s + i - 9));
    }
}
void wr(const bigint& a) {
    printf("%d", a.empty() ? 0 : a.back());
    for(int i = (int)a.size() - 2; i >= 0; --i) {
        printf("%09d", a[i]);
    }
}

bool operator< (const bigint& a, const bigint& b) {
    if(a.size() != b.size()) {
        return a.size() < b.size();
    }
    for(int i = a.size(); i--; ) {
        if(a[i] != b[i]) {
            return a[i] < b[i];
        }
    }
    return 0;
}

void operator+= (bigint& a, const bigint& b) {
    int carry = 0;
    for(unsigned i = 0; i < max(a.size(), b.size()) || carry; ++i) {
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
    for(unsigned i = 0; i < b.size() || carry; ++i) {
        a[i] -= carry + (i < b.size() ? b[i] : 0);
        carry = (a[i] < 0);
        if(carry) a[i] += B;
    }
    while(a.size() > 1 && a.back() == 0) {
        a.pop_back();
    }
}

const int N = 301;
bigint s, nCr[N][N];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    nCr[0][0].push_back(1);
    for(int i = 1; i <= n; ++i) {
        nCr[i][0].push_back(1);
        nCr[i][i].push_back(1);
        for(int j = 1, k = i >> 1; j <= k; ++j) {
            nCr[i][j] = nCr[i - 1][j];
            nCr[i][j] += nCr[i - 1][j - 1];
            nCr[i][i - j] = nCr[i][j];
        }
    }
    rd(s);
    for(int i = 0, j = 1; i < k; ++i) {
        while(nCr[n - j][k - 1 - i] < s) {
            s -= nCr[n - j][k - 1 - i];
            ++j;
        }
        if(i) putchar(' ');
        printf("%d", j++);
    }
    putchar('\n');
    bigint res(1, 1);
    for(int i = 0, pre = 0, b; i < k; ++i) {
        scanf("%d", &b);
        for(int j = pre + 1; j < b; ++j) {
            res += nCr[n - j][k - 1 - i];
        }
        pre = b;
    }
    wr(res);
    return 0;
}
