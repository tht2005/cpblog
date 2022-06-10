#include <bits/stdc++.h>

using namespace std;

const int md = (int)1e9 + 7;
void add(int& a, int b) {
    a += b;
    if(a >= md) a -= md;
}

const int N = 300005;
int n, v[N];
pair<int, int> a[N], f[N];

void update(int x, pair<int, int> d) {
    for(; x < N; x |= x + 1) {
        if(f[x].first < d.first) {
            f[x] = d;
        }
        else if(f[x].first == d.first) {
            add(f[x].second, d.second);
        }
    }
}
pair<int, int> query(int x) {
    pair<int, int> ret(0, 1);
    for(; x >= 0; x = (x & (x + 1)) - 1) {
        if(ret.first < f[x].first) {
            ret = f[x];
        }
        else if(ret.first == f[x].first) {
            add(ret.second, f[x].second);
        }
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &a[i].first, &a[i].second);
        v[i] = a[i].second;
    }
    sort(v, v + n);
    for(int i = 0; i < n; ++i) {
        a[i].second = v - lower_bound(v, v + n, a[i].second);
    }
    sort(a, a + n);
    for(int i = 0; i < n; ++i) {
        pair<int, int> tmp = query(-a[i].second - 1);
        ++tmp.first;
        update(-a[i].second, tmp);
    }
    pair<int, int> r = query(N - 1);
    printf("%d\n%d", r.first, r.second);
    return 0;
}
