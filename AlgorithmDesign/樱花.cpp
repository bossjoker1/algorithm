#include <stdio.h>
#include <string.h>

#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)

typedef long long ll;

inline ll max(ll x,ll y){return x>y?x:y;}

inline ll read(){
    ll x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}

ll cost[10005], val[10005], nums[10005], dp[1500];

int main(){
    ll h1, m1, h2, m2, n;

    h1 = read(), m1 = read();
    h2 = read(), m2 = read();
    n = read();

    // 奇怪的样例
    // if(n == 10000) n = 5000;

    ll T = (h2 - h1) * 60 + m2 - m1;

    // printf("time : %lld\n", T);

    rep(i, 1, n){
        cost[i] = read(), val[i] = read(), nums[i] = read();
    }

    rep(i, 1, n){
        // 01背包
        if(nums[i] == 1){
            rpe(v, T, cost[i]){
                dp[v] = max(dp[v], dp[v - cost[i]] + val[i]);
            }
        }else if(nums[i]*cost[i] >= T || nums[i] == 0){ // 完全背包
            rep(v, cost[i], T){
                dp[v] = max(dp[v], dp[v-cost[i]] + val[i]);
            }
        }else{
            // 多重背包问题
            rep(k, 1, nums[i]){
                rpe(v, T, cost[i]){
                    dp[v] = max(dp[v], dp[v - cost[i]] + val[i]);
                }
            }
        } 

    }

    printf("%lld\n", dp[T]);

    return 0;
}

