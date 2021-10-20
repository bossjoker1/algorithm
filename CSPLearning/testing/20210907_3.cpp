// 爆内存加只能过部分点
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f3f3f3f3f
#define N 1001000
#define M 5001000

typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat; // 矩阵

typedef vector<pair<ll, ll>> graph[M];
vector<ll>have[N];
priority_queue<ll, vector<ll>, greater<ll> >pq2;

int main() {
    int n, m;   
    graph dis;
    cin >> n >> m;
    // init the graph
    for (int i = 0; i < m; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        dis[a].push_back(make_pair(b, d));
        dis[b].push_back(make_pair(a, d));
    }
    // read the date
    // 快递点到其它点的最短路径
    // 注意有环的bfs写法
    ll dn[N];
    int visit[N] = { 0 };
    for (int i = 0; i <= n; i++) 
        dn[i] = INF;
    dn[0] = 0;
    queue <ll> q;
    q.push(0);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        visit[now] = 0;
        for (int i = 0; i < dis[now].size(); i++) {
            ll x = dis[now][i].first;
            if (dn[x] < dn[now] + dis[now][i].second)
                continue;
            dn[x] = dn[now] + dis[now][i].second;
            if (!visit[x]) {
                q.push(x);
                visit[x] = 1;
            }
        }
    }
    //for (int i = 1; i <= n; i++)
    //    printf("%d %d\n", i, dn[i]);
    int sum = 0;
    ll t;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &t);
        have[t].push_back(dn[i]);
        // 先计算可得到的总收入
        sum += dn[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < have[i].size(); j++) pq2.push(have[i][j]);
        // cout << "i: " << i << " " << "size: " << pq2.size() << endl;
        for (; pq2.size() > i;)
        {
            // 说明超过当天，需要减去
            sum -= 2 * pq2.top();
            pq2.pop();
        }
    }
    cout << sum;
    

    return 0;
}