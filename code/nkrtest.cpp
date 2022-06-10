#include <bits/stdc++.h>

using namespace std;

int rd() {
    char c = getchar(); while(c < '0' || c > '9') c = getchar();
    int n = 0; while('0' <= c && c <= '9') n = (n << 3) + (n << 1) + c - '0', c = getchar();
    return n;
}
void wr(int n) {
    static char buf[20];
    int i = 0; do buf[i++] = n % 10 + '0'; while(n /= 10);
    while(i--) putchar(buf[i]);
}

const int N = 200005;
const int B = 311;

const int md = (int)1e9 + 7;
int add(int a, int b) { a += b; if(a >= md) a -= md; return a; }
#define mul(a, b) ((long long)(a) * (b) % md)

int d[N], b[N];
char s[1000006];
map<int, int> cnt;
vector<pair<int, int>> aj[N];

void dfs(const vector<int>& x, int h) {
    cnt[h] += x.size();
    vector<int> v0, v1;
    for(int v : x) {
        for(const auto& [w, u] : aj[v]) {
            if(b[u] != 1 && d[u] == d[v] + 1) {
                if(w == 0) {
                    b[u] = -2;
                }
                else if(b[u] == -1) {
                    b[u] = -3;
                }
            }
        }
    }
    for(int v : x) {
        for(const auto& [w, u] : aj[v]) {
            if(b[u] != 1 && d[u] == d[v] + 1) {
                if(w == 0) {
                    v0.push_back(u);
                    b[u] = 1;
                }
                else if(b[u] == -3) {
                    v1.push_back(u);
                    b[u] = 1;
                }
            }
        }
    }
    if(!v0.empty()) dfs(v0, add(mul(h, B), 1));
    if(!v1.empty()) dfs(v1, add(mul(h, B), 2));
}

int main() {
    int n = rd(), m = rd();
    while(m--) {
        int u = rd() - 1, v = rd() - 1, w = rd();
        aj[u].emplace_back(w, v);
        aj[v].emplace_back(w, u);
    }
    queue<int> q;
    q.push(0);
    memset(d, 0xff, n * sizeof *d);
    d[0] = 0;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(const auto& [w, u] : aj[v]) {
            if(d[u] == -1) {
                d[u] = d[v] + 1;
                q.push(u);
            }
        }
    }
    memset(b, 0xff, n * sizeof *b);
    vector<int> v(1, 0);
    b[0] = 1;
    dfs(v, 0);
    int _ = rd();
    char c = getchar();
    while(_--) {
        int h = 0, j = 0, k = 1;
        while(c != '0' && c != '1') c = getchar();
        m = 0;
        while(c == '0' || c == '1') {
            h = add(mul(h, B), c + 1 - '0');
            ++m;
            if(cnt.count(h)) {
                j = m;
                k = cnt[h];
            }
            c = getchar();
        }
        putchar((j == m) ? '+' : '-');
        wr(j);
        putchar(' ');
        wr(k);
        putchar('\n');
    }
    return 0;
}
