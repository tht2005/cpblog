#include <bits/stdc++.h>

using namespace std;

int main() {
    char a[61], b[61], res[61];
    scanf("%s %s", a, b);
    int n = strlen(a);
    int cnt[10];
    for(int i = n; i >= 0; --i) {
        memset(cnt, 0, sizeof(cnt));
        for(int j = 0; j < n; ++j) {
            ++cnt[b[j] - '0'];
        }
        for(int j = 0; j < i; ++j) {
            if((--cnt[a[j] - '0']) < 0) {
                goto next_i_1;
            }
            res[j] = a[j];
        }
        if(i < n) {
            res[i] = 0;
            for(int j = a[i] - '0' + 1; j < 10; ++j) {
                if(cnt[j]) {
                    res[i] = j + '0';
                    --cnt[j];
                    break;
                }
            }
            if(!res[i]) {
                goto next_i_1;
            }
        }
        for(int j = i + 1; j < n; ++j) {
            for(int k = 0; k < 10; ++k) {
                if(cnt[k]) {
                    res[j] = k + '0';
                    --cnt[k];
                    break;
                }
            }
        }
        res[n] = 0;
        puts(res);
        goto next_query;
next_i_1:;
    }
    puts("0");
next_query:;
    for(int i = n; i--; ) {
        memset(cnt, 0, sizeof(cnt));
        for(int j = 0; j < n; ++j) {
            ++cnt[b[j] - '0'];
        }
        for(int j = 0; j < i; ++j) {
            if((--cnt[a[j] - '0']) < 0) {
                goto next_i_2;
            }
            res[j] = a[j];
        }
        res[i] = 0;
        for(int j = a[i] - '0'; j--; ) {
            if(cnt[j]) {
                res[i] = j + '0';
                --cnt[j];
                break;
            }
        }
        if(!res[i] || (!i && res[i] == '0')) {
            goto next_i_2;
        }
        for(int j = i + 1; j < n; ++j) {
            for(int k = 10; k--; ) {
                if(cnt[k]) {
                    res[j] = k + '0';
                    --cnt[k];
                    break;
                }
            }
        }
        res[n] = 0;
        puts(res);
        return 0;
next_i_2:;
    }
    puts("0");
    return 0;
}
