#include <bits/stdc++.h>

using namespace std;

const int N = 30001;
int f[N];
vector<int> L[N];

int main() {
    int n;
    scanf("%d", &n);
    while(n--) {
        int s, t;
        scanf("%d %d", &s, &t);
        L[t].push_back(s);
    }
    f[0] = 0;
    for(int i = 1; i < N; ++i) {
        f[i] = f[i - 1];
        for(int j : L[i]) {
            f[i] = max(f[i], f[j] + i - j);
        }
    }
    printf("%d", f[N - 1]);
    return 0;
}
