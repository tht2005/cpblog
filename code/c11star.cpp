#include <bits/stdc++.h>

using namespace std;

const int M = 3003;
const int N = 202;

char s[M][N];
int f[M + N][N][26];

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    for(int i = 0; i < m; ++i) {
        scanf("%s", s[i]);
    }
    long long res = 0;
    for(int k = 1; k < m + n - 2; ++k) {
        for(int i = min(k, m - 1); i > 0; --i) {
            for(int j = 1; j <= i && j < n + i - k; ++j) {
                if(s[i][k - i] != '.' && s[i][k - i] == s[i - j][k - i + j]) {
                    res += f[i + i - k + n][j][s[i][k - i] - 'a'];
                    ++f[i + i - k + n][j][s[i][k - i] - 'a'];
                }
            }
        }
    }
    printf("%lld", res);
    return 0;
}
