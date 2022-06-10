#include <bits/stdc++.h>

using namespace std;

const int INF = (int)2e9 + 1;
int k, f[27][27];
bool used[26];
char s[26];

int main() {
    memset(f, 0, sizeof(f));
    f[0][0] = 1;
    for(int i = 1; i < 27; ++i) {
        f[i][0] = 1;
        for(int j = 1; j <= i; ++j) {
            long long val = (long long)f[i - 1][j - 1] * i;
            if(val > INF) val = INF;
            f[i][j] = val;
        }
    }
    int q;
    scanf("%d", &q);
    while(q--) {
        int n, m;
        char o;
        scanf("%d %d %c", &n, &m, &o);
        memset(used, 0, n * sizeof *used);
        if(o == 'P') {
            scanf("%s", s);
            int res = 1;
            for(int i = 0; i < m; ++i) {
                if(s[i] - 'a' >= n || used[s[i] - 'a']) {
                    puts("Incorrect data");
                    goto next_query;
                }
                for(int j = 0; j < s[i] - 'a'; ++j) {
                    if(used[j]) continue;
                    res += f[n - i - 1][m - i - 1];
                }
                used[s[i] - 'a'] = 1;
            }
            printf("%d\n", res);
        }
        else {
            scanf("%d", &k);
            if(k > f[n][m]) {
                puts("Incorrect data");
                goto next_query;
            }
            for(int i = 0; i < m; ++i) {
                int j = 0;
                for(;; ++j) {
                    if(!used[j]) {
                        if(k <= f[n - i - 1][m - i - 1]) {
                            break;
                        }
                        k -= f[n - i - 1][m - i - 1];
                    }
                }
                used[j] = 1;
                printf("%c", j + 'a');
            }
            putchar('\n');
        }
next_query:;
    }
    return 0;
}
