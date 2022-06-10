#include <bits/stdc++.h>

using namespace std;

const int B = 1e9;
typedef vector<int> bigint;

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

void print(const bigint& a) {
    printf("%d", a.back());
    for(int i = (int)a.size() - 2; i >= 0; --i) {
        printf("%09d", a[i]);
    }
}

int main() {
    string s;
    cin >> s;
    bigint f(1, 1), cnt(1, 1);
    for(char c : s) {
        if(c == '*') {
            f *= 5;
            f += cnt;
            cnt *= 3;
        }
        else {
            if(c != 'P') {
                f *= 2;
                if(c == 'R') {
                    f += cnt;
                }
            }
        }
    }
    print(f);
    return 0;
}
