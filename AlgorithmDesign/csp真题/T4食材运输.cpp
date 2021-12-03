// 感觉能水30分，但是不知道咋就超时了。。。
#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)
#define inf 0x3f3f3f3f
const int maxn = 100+5;
const int maxk = 10+5;
inline int max(int x, int y) { return x > y ? x : y; }
inline int read() {
    int x = 0, f = 1; char ch = ' ';
    while (ch < '0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + (ch ^ 48); ch = getchar(); }
    return f == 1 ? x : -x;
}

int N, M, K, hotel2food[maxn][maxk], cor[maxn][maxn];

int main(){
    N = read(), M = read(), K = read();
    vector<int> need[K+1];
    memset(cor, -1, sizeof(cor));
    rep(i, 1, N){
        rep(j, 1, K){
            hotel2food[i][j] = read();
            if(hotel2food[i][j]) need[j].push_back(i);
        }
    }
    int x, y, d;
    // 双向边
    int cnt[maxn];
    rep(i, 1, N-1){
        x = read(),  y = read(), d = read();
        cor[x][y] = cor[y][x] = d;
        cnt[x]++, cnt[y]++;
    }
    // 找一个链头
    int k;
    rep(i, 1, N){
        if(cnt[i] == 1) {
            k = i;
            break;
        }
    }
    // 以链头开始，记录前缀和
    int dis[maxn], count=1;
    dis[k] = 0;
    int temp = k;
    while(count<=N){
        rep(i, 1, N){
            if(cor[temp][i]){
                dis[i] += cor[temp][i];
                temp = i;
                count++;
            }
        }
    }

    int maxt = -1;
    rep(i, 1, K){
        // 放在任意酒店
        int mint = inf;
        rep(j, 1, N){
            int sum=0;
            for(auto&t:need[i]){
                sum += abs(dis[t] - dis[j]);
            }
            mint = min(mint, sum);
        }
        maxt = max(maxt, mint);
    }

    cout<<maxt<<endl;
    return 0;
}