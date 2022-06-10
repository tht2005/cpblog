#include <bits/stdc++.h>

using namespace std;

const int N = 5005;
int h[N];
pair<int, int> a[N];

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%d %d", &a[i].first, &a[i].second);
        }
        sort(a, a + n);
        for(int i = 1; i <= n; ++i) {
            h[i] = 2e9;
        }
        for(int i = 0; i < n; ++i) {
            int k = lower_bound(h + 1, h + 1 + n, -a[i].second) - h;
            h[k] = -a[i].second;
        }
        for(int i = n;; --i) {
            if(h[i] != 2e9) {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
