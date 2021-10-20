// 暴力无脑40分，多轮的参考答案都看不懂
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f3f3f3f3f

typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat; // 矩阵

// 大顶堆
priority_queue<ll, vector<ll>, greater<ll> >pq2;

int main() {
    int n, q;
    cin >> n;
    vec dp;
    dp.push_back(-1);
    for (int i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        dp.push_back(temp);
    }

    cin >> q;

    int l, r;
    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        ll sum = 0;
        vec tp;
        while (l <= r) {
            if (count(tp.begin(), tp.end(), dp[l])) {
                sum++;
                vector<ll>().swap(tp);
                tp.push_back(dp[l]);
                l++;
            }
            else {
                tp.push_back(dp[l]);
                l++;
            }
        }
        cout << sum + 1 << endl;
    }
    return 0;
}