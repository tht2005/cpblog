#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int tot = 0;
    vector<int> a;
    for(int i = 0, t, k, b; i < n; ++i) {
        scanf("%d %d", &t, &k);
        while(k--) {
            scanf("%d", &b);
            a.push_back(max(0, b - tot));
        }
        tot += t;
    }
    sort(a.begin(), a.end());
    printf("%d", tot + a[m - 1]);
    return 0;
}
