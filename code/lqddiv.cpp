#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 32;
int a[N];

void try1(int i, int r, LL s, vector<LL>& v) {
    if(i == r) {
        v.push_back(s);
    }
    else {
        try1(i + 1, r, s + a[i], v);
        try1(i + 1, r, s - a[i], v);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    vector<LL> L, R;
    try1(0, n >> 1, 0, L);
    try1(n >> 1, n, 0, R);
    sort(R.begin(), R.end());
    LL res = numeric_limits<LL>::max(), cnt = 0;
    for(LL x : L) {
        auto it = lower_bound(R.begin(), R.end(), -x);
        if(it != R.end()) {
            if(res > abs(x + (*it))) {
                res = abs(x + (*it));
                cnt = upper_bound(R.begin(), R.end(), *it) - lower_bound(R.begin(), R.end(), *it);
            }
            else if(res == abs(x + (*it))) {
                cnt += upper_bound(R.begin(), R.end(), *it) - lower_bound(R.begin(), R.end(), *it);
            }
        }
        if(it != R.begin()) {
            --it;
            if(res > abs(x + (*it))) {
                res = abs(x + (*it));
                cnt = upper_bound(R.begin(), R.end(), *it) - lower_bound(R.begin(), R.end(), *it);
            }
            else if(res == abs(x + (*it))) {
                cnt += upper_bound(R.begin(), R.end(), *it) - lower_bound(R.begin(), R.end(), *it);
            }
        }
    }
    printf("%lld %lld", res, cnt / 2);
    return 0;
}
