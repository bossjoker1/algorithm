#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)

const int maxn = 100005;

inline int max(int x, int y) { return x > y ? x : y; }

inline int read() {
    int x = 0, f = 1; char ch = ' ';
    while (ch < '0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + (ch ^ 48); ch = getchar(); }
    return f == 1 ? x : -x;
}

int n, cnt0[maxn], cnt1[maxn];
vector<pair<int, int>> vec(maxn);

int main() {
    memset(cnt0, 0, sizeof(cnt0));
    memset(cnt1, 0, sizeof(cnt1));
    n = read();
    rep(i, 1, n) {
        vec[i].first = read();
        vec[i].second = read();
    }

    sort(vec.begin()+1, vec.begin() + n+1);
    rep(i, 1, n) {
        cnt0[i] = cnt0[i-1] + (vec[i].second == 0);
    }

    rpe(i, n, 1) {
        cnt1[i] = cnt1[i+1] + (vec[i].second == 1);
    }
    int ans = -1, k=-1;
    rep(i, 1, n) {
        // 注意重复值第一次处理为正确结果
        // 再遇到需要跳过
        if (vec[i].first == vec[i - 1].first) continue;
        if (cnt0[i-1] + cnt1[i] >= ans) {
            ans = cnt0[i-1] + cnt1[i];
            k = vec[i].first;
        }
    }
    printf("%d\n", k);
    return 0;
}