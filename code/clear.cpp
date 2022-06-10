#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int L = 17;
const int S = 81 * L + 1;

bool isclear[S];
int a[L], digitsum[S];
LL f[L][S];
vector<int> aj[S];

void dfs(int v) {
    isclear[v] = 1;
    for(int u : aj[v]) {
        if(!isclear[u]) {
            dfs(u);
        }
    }
}

LL calc(LL _) {
    int n = 0;
    do {
        a[n++] = _ % 10;
    } while(_ /= 10);
    LL res = f[n - 1][0];
    int s = 0;
    for(int i = n; i--; ) {
        for(int j = (i + 1 == n); j < a[i]; ++j) {
            res += f[i][s + j * j];
        }
        s += a[i] * a[i];
    }
    return res + isclear[s];
}

int main() {
    digitsum[0] = 0;
    for(int i = 1; i < S; ++i) {
        digitsum[i] = digitsum[i / 10] + (i % 10) * (i % 10);
        aj[digitsum[i]].push_back(i);
    }
    dfs(1);
    for(int i = 0; i < S; ++i) {
        f[0][i] = isclear[i];
    }
    for(int i = 1; i < L; ++i) {
        for(int j = 0; j < S; ++j) {
            for(int c = 0; c < 10 && j + c * c < S; ++c) {
                f[i][j] += f[i - 1][j + c * c];
            }
        }
    }
    int q;
    scanf("%d", &q);
    while(q--) {
        LL n, m;
        scanf("%lld %lld", &n, &m);
        LL cnt = calc(n);
        LL l = n + 1, r = 9005752047620326, res = r;
        while(l <= r) {
            LL mid = (l + r) >> 1;
            if(calc(mid) < cnt + m) {
                l = mid + 1;
            }
            else {
                res = mid;
                r = mid - 1;
            }
        }
        printf("%lld\n", res);
    }
    return 0;
}
