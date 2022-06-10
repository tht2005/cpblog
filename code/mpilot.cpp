#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int res = 0;
    priority_queue<int> q;
    for(int i = 1; i <= n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        res += x;
        q.push(x - y);
        if(i & 1) {
            res -= q.top();
            q.pop();
        }
    }
    printf("%d", res);
    return 0;
}
