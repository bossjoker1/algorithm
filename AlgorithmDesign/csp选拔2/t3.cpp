#include <bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)

#define MAX_N 200005

typedef long long ll;

typedef pair<ll, ll> PLL;

inline ll max(ll x, ll y) { return x > y ? x : y; }
inline ll min(ll x, ll y) { return x < y ? x : y; }

inline ll read() {
    ll x = 0, f = 1; char ch = ' ';
    while (ch < '0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + (ch ^ 48); ch = getchar(); }
    return f == 1 ? x : -x;
}

ll n, r;
PLL puzzles[MAX_N];
PLL points[MAX_N];

int main() {
    n = read(), r = read();
    rep(i, 1, n) {
        puzzles[i].first = read(), puzzles[i].second = read();
    }
    ll x, y;
    ll left, right;
    rep(i, 1, n) {
        // printf("%lld, %lld\n", puzzles[i].first, puzzles[i].second);
        x = puzzles[i].first, y = puzzles[i].second;
        // 求需要的区间
        int d = sqrt(r * r * 1.0 - y * y * 1.0);
        // 直接截断
        left = x - d;
        right = x + d;
        points[i].first = left, points[i].second = right;
    }

    sort(points + 1, points + n + 1);

    ll res = 1;
    ll border = points[1].second;
    rep(i, 2, n) {
        if (points[i].first > border) {
            res += 1;
            border = points[i].second;
        }else{
            border = min(border, points[i].second);
        }
    }
    printf("%lld\n", res);

    return 0;
}