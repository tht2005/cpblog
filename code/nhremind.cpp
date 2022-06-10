#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long LL;

const int N = 1000006;
const int B = 311;

int n;
LL pw[N];
vector<LL> h[N], ha;

LL get(const vector<LL>& a, int l, int r) {
    return a[r] - a[l] * pw[r - l];
}

bool check(int L) {
    vector<LL> v;
    for(int i = 0; i < n; ++i) {
        const vector<LL>& b = h[i];
        for(size_t j = 0; j + L < b.size(); ++j) {
            v.push_back(get(b, j, j + L));
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    const vector<LL>& a = h[n];
    for(size_t i = 0; i + L < a.size(); ++i) {
        if(!binary_search(v.begin(), v.end(), get(a, i, i + L))) {
            return 1;
        }
    }
    return 0;
}

string b;

bool cmp(const vector<LL>& a, int i, int j) {
    for(int k = 1 << 19; k > 0; k >>= 1) {
        if(i + k < a.size() && j + k < a.size() && get(a, i, i + k) == get(a, j, j + k)) {
            i += k;
            j += k;
        }
    }
    return (i < b.size() ? b[i] : 0) < (j < b.size() ? b[j] : 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    pw[0] = 1;
    for(int i = 1; i < N; ++i) {
        pw[i] = pw[i - 1] * B;
    }
    cin >> n;
    for(int i = 0; i <= n; ++i) {
        cin >> b;
        h[i].resize(b.size() + 1);
        h[i][0] = 0;
        for(size_t j = 0; j < b.size(); ++j) {
            h[i][j + 1] = h[i][j] * B + b[j];
        }
    }
    int l = 1, r = h[n].size() - 1, res = -1;
    while(l <= r) {
        int m = (l + r) >> 1;
        if(check(m)) {
            res = m;
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    vector<LL> v;
    for(int i = 0; i < n; ++i) {
        const vector<LL>& b = h[i];
        for(size_t j = 0; j + res < b.size(); ++j) {
            v.push_back(get(b, j, j + res));
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    const vector<LL>& a = h[n];
    int pos = -1;
    for(size_t i = 0; i + res < a.size(); ++i) {
        if(!binary_search(v.begin(), v.end(), get(a, i, i + res))) {
            if(pos == -1 || cmp(h[n], i, pos)) {
                pos = i;
            }
        }
    }
    cout << b.substr(pos, res);
    return 0;
}
