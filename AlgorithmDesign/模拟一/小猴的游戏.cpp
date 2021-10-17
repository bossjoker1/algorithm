#include <stdio.h>
#include <string.h>
#include <math.h>
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

ll h[100005], dp[100005];

int main(){
    ll n = read(), d = read();
    
    rep(i, 1, n){
        h[i] = read();
    }

    // dp[i]表示到 i 或者经过i时的走的序列长度

    dp[1] = 1;

    rep(i, 1, n){
        dp[i] = 1;
    }

    rep(i, 1, n){
        rep(j, 1, i){
            if(abs(h[j] - h[i]) >= d){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    ll ans = -1;

    rep(i, 1, n){
        ans  = max(ans, dp[i]);
    }
    printf("%lld\n", ans);
    return 0;
}