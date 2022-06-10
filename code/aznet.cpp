#include <bits/stdc++.h>

using namespace std;

struct edge {
    int u, v, i;
};

const int N = 10004;
const int M = 100005;

int p[N];
void init(int n) {
    memset(p, 0xff, n * sizeof *p);
}
int rt(int x) {
    return (p[x] < 0) ? x : (p[x] = rt(p[x]));
}
bool ae(int x, int y) {
    if((x = rt(x)) == (y = rt(y))) {
        return 0;
    }
    if(p[y] < p[x]) {
        swap(x, y);
    }
    p[x] += p[y];
    p[y] = x;
    return 1;
}

int a[N], b[N], S[M];
edge e[M], f[M];

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        int n, m;
        scanf("%d %d", &n, &m);
        a[0] = 0;
        for(int i = 1; i < n; ++i) {
            scanf("%d", a + i);
        }
        b[0] = 0;
        for(int i = 1; i < n; ++i) {
            scanf("%d", b + i);
        }
        int c = 0, d = 0;
        for(int i = 0, u, v, t; i < m; ++i) {
            scanf("%d %d %d", &u, &v, &t);
            if(t == 1) {
                e[c].u = u - 1;
                e[c].v = v - 1;
                e[c].i = i;
                ++c;
            }
            else {
                f[d].u = u - 1;
                f[d].v = v - 1;
                f[d].i = i;
                ++d;
            }
        }
        int min1 = 0, max1 = 0;
        init(n);
        for(int i = 0; i < d; ++i) {
            ae(f[i].u, f[i].v);
        }
        for(int i = 0; i < c; ++i) {
            if(ae(e[i].u, e[i].v)) {
                S[min1++] = i;
            }
        }
        init(n);
        for(int i = 0; i < c; ++i) {
            if(ae(e[i].u, e[i].v)) {
                ++max1;
            }
        }
        int x = min1;
        for(int i = min1 + 1; i <= max1; ++i) {
            if(a[x] + b[n - 1 - x] > a[i] + b[n - 1 - i]) {
                x = i;
            }
        }
        init(n);
        for(int i = 0; i < min1; ++i) {
            ae(e[S[i]].u, e[S[i]].v);
            printf("%d ", e[S[i]].i + 1);
        }
        for(int i = 0, cnt = x - min1; i < c && cnt; ++i) {
            if(ae(e[i].u, e[i].v)) {
                printf("%d ", e[i].i + 1);
                --cnt;
            }
        }
        for(int i = 0; i < d; ++i) {
            if(ae(f[i].u, f[i].v)) {
                printf("%d ", f[i].i + 1);
            }
        }
        putchar('\n');
    }
    return 0;
}
