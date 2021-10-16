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

ll v[30], w[30], dp[30005];

int main(){
    ll n, m;
    n = read(), m = read();

    rep(i, 1, m){
        v[i] = read(), w[i] = read();
        w[i] = v[i] * w[i];
    }

    rep(i, 1, m){
        rpe(j, n, v[i]){
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    printf("%lld\n", dp[n]);
    return 0;
}