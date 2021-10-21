#include <cstdio>
#define int long long 
/*
#define self rt, l, r
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
*/
//这些宏定义可以让代码更简洁
using namespace std;
const int N = 1e5 + 5;
int n, m, a[N], t[N<<2], x, y, w, lazy[N<<2];
void build(int rt, int l, int r) {
    if (l == r) { t[rt] = a[l]; return; }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    t[rt] = t[rt<<1] + t[rt<<1|1];
}
void updata(int rt, int l, int r, int w) {
    t[rt] += (r - l + 1) * w;
    lazy[rt] += w;
}
void pushdown(int rt, int l, int r) {
    int mid = (l + r) >> 1;
    updata(rt << 1, l, mid, lazy[rt]);
    updata(rt << 1 | 1, mid + 1, r, lazy[rt]);
    lazy[rt] = 0;
}
void add(int rt, int l, int r) {
    if (x <= l && r <= y) {
        updata(rt, l, r, w);
        return;
    }
    pushdown(rt, l, r);
    int mid = (l + r) >> 1;
    if (x <= mid) add(rt << 1, l, mid);
    if (y > mid) add(rt << 1 | 1, mid + 1, r);
    t[rt] = t[rt<<1] + t[rt<<1|1];
}
int sum(int rt, int l, int r) {
    if (x <= l && r <= y) return t[rt];
    int mid = (l + r) >> 1, ans = 0;
    pushdown(rt, l, r);
    if (x <= mid) ans += sum(rt << 1, l, mid);
    if (y > mid) ans += sum(rt << 1 | 1, mid + 1, r);
    return ans;
}
signed main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    build(1, 1, n);
    while (m--) {
        int t;
        scanf("%lld%lld%lld", &t, &x, &y);
        if (t == 1) scanf("%lld", &w), add(1, 1, n);
        else printf("%lld\n", sum(1, 1, n));
    }
    return 0;
}
