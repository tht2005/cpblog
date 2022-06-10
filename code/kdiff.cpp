#include <bits/stdc++.h>

using namespace std;

const int N = 300005;
int a[N], f[N];
deque<int> d1, d2;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int res = 1;
    for(int i = 1, j = 1; i <= n; ++i) {
        scanf("%d", a + i);
        while(!d1.empty() && a[i] > d1.back()) {
            d1.pop_back();
        }
        d1.push_back(a[i]);
        while(!d2.empty() && a[i] < d2.back()) {
            d2.pop_back();
        }
        d2.push_back(a[i]);
        while(d1.front() - d2.front() > k) {
            if(d1.front() == a[j]) {
                d1.pop_front();
            }
            if(d2.front() == a[j]) {
                d2.pop_front();
            }
            ++j;
        }
        f[i] = max(f[i - 1], i + 1 - j);
        res = max(res, f[j - 1] + i + 1 - j);
    }
    printf("%d", res);
    return 0;
}
