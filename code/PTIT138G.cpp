#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while(scanf("%d", &n), n) {
        int s = 0;
        vector<pair<int, int>> f;
        f.emplace_back(0, 0);
        for(int i = 0, a; i < n; ++i) {
            scanf("%d", &a);
            s += a;
            for(size_t j = 0, sz = f.size(); j < sz; ++j) {
                pair<int, int> nw(f[j]);
                nw.first += a;
                if(nw.first > nw.second) {
                    swap(nw.first, nw.second);
                }
                f.push_back(nw);
                nw = f[j];
                nw.second += a;
                if(nw.first > nw.second) {
                    swap(nw.first, nw.second);
                }
                f.push_back(nw);
            }
            sort(f.begin(), f.end());
            f.erase(unique(f.begin(), f.end()), f.end());
        }
        int res = s;
        for(const pair<int, int>& p : f) {
            res = min(res, max(max(p.first, p.second), s - p.first - p.second));
        }
        printf("%d\n", res);
    }
    return 0;
}
