#include <bits/stdc++.h>

using namespace std;

int s[1001][1001];

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    vector<pair<int, int>> r;
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            char c;
            scanf(" %c", &c);
            if((s[i][j] + c) & 1) {
                ++s[i][j];
                r.emplace_back(i, j);
            }
            s[i][j + 1] += s[i][j];
            s[i + 1][j] += s[i][j];
            s[i + 1][j + 1] -= s[i][j];
        }
    }
    printf("%d\n", r.size());
    for(const auto& [i, j] : r) {
        printf("%d %d %d %d\n", i + 1, j + 1, m - i, n - j);
    }
    return 0;
}
