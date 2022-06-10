#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int md = 1000000007;
#define mul(a, b) ((long long)(a) * (b) % md)

const int K = 62;
void mat_mul(int a[K][K], int b[K][K], int res[K][K]) {
    static int c[K][K];
    for(int i = 0; i < K; ++i) {
        for(int j = 0; j < K; ++j) {
            LL val = 0;
            for(int k = 0; k < K; ++k) {
                val += mul(a[i][k], b[k][j]);
            }
            c[i][j] = val % md;
        }
    }
    for(int i = 0; i < K; ++i) {
        for(int j = 0; j < K; ++j) {
            res[i][j] = c[i][j];
        }
    }
}
void mat_mul_2(int a[K], int b[K][K], int res[K]) {
    static int c[K];
    for(int i = 0; i < K; ++i) {
        LL val = 0;
        for(int j = 0; j < K; ++j) {
            val += mul(a[j], b[j][i]);
        }
        c[i] = val % md;
    }
    for(int i = 0; i < K; ++i) {
        res[i] = c[i];
    }
}

#define id(c) (\
    ('a' <= (c) && (c) <= 'z') ? ((c) - 'a') : (\
        ('A' <= (c) && (c) <= 'Z') ? ((c) - 'A' + 26) : ((c) - '0' + 52)\
    )\
)

struct dt {
    int k, y;
    LL x;
    bool operator< (const dt& b) const {
        if(x != b.x) return x < b.x;
        return k < b.k;
    }
} a[1001];

int c[60][K][K];

int main() {
    LL n;
    int mm, kk;
    scanf("%lld %d %d", &n, &mm, &kk);
    int(*b)[K] = c[0];
    for(int i = 0; i < K; ++i) {
        for(int j = 0; j < K; ++j) {
            b[i][j] = 1;
        }
    }
    while(mm--) {
        char x, y;
        scanf(" %c %c", &x, &y);
        b[id(x)][id(y)] = b[id(y)][id(x)] = 0;
    }
    for(int i = 1; i < 60; ++i) {
        mat_mul(c[i - 1], c[i - 1], c[i]);
    }
    for(int i = 0; i < kk; ++i) {
        int k;
        LL x;
        char y;
        scanf("%d %lld %c", &k, &x, &y);
        a[i].k = k;
        a[i].x = x;
        a[i].y = id(y);
    }
    sort(a, a + kk);
    int m[K];
    for(int i = 0; i < K; ++i) {
        m[i] = 1;
    }
    int i = 0;
    while(i < kk && a[i].x == 1 && a[i].k == 0) {
        m[a[i].y] = 0;
        ++i;
    }
    int pre_y = -1;
    while(i < kk && a[i].x == 1 && a[i].k == 1) {
        if(pre_y != -1 && pre_y != a[i].y) {
            putchar('0');
            return 0;
        }
        if(pre_y == -1) {
            for(int j = 0; j < K; ++j) {
                if(j != a[i].y) {
                    m[j] = 0;
                }
            }
            pre_y = a[i].y;
        }
        ++i;
    }
    LL pre_x = 1;
    for(int j = i; i < kk; i = j) {
        for(int k = 60; k--; ) {
            if((a[i].x - pre_x) >> k & 1) {
                mat_mul_2(m, c[k], m);
            }
        }
        pre_x = a[i].x;
        while(j < kk && a[j].x == a[i].x && a[j].k == 0) {
            m[a[j].y] = 0;
            ++j;
        }
        int yy = -1;
        while(j < kk && a[j].x == a[i].x && a[j].k == 1) {
            if(yy != -1 && yy != a[j].y) {
                putchar('0');
                return 0;
            }
            yy = a[j].y;
            ++j;
        }
        if(yy != -1) {
            if(m[yy] == 0) {
                putchar('0');
                return 0;
            }
            for(int k = 0; k < K; ++k) {
                if(k != yy) {
                    m[k] = 0;
                }
            }
        }
    }
    if(pre_x < n) {
        for(int i = 60; i--; ) {
            if((n - pre_x) >> i & 1) {
                mat_mul_2(m, c[i], m);
            }
        }
    }
    LL res = 0;
    for(int i = 0; i < K; ++i) {
        res += m[i];
    }
    printf("%lld", res % md);
    return 0;
}
