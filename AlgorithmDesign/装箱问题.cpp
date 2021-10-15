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

// dp[i] 表示剩余价值

ll dp[20005], v[35];

int main(){

    ll V = read(), n = read();

    rep(i, 1, n){
        v[i] = read();
    }

    rep(i, 1, n){
        rpe(j, V, v[i]){
            dp[j] = max(dp[j], dp[j - v[i]] + v[i]);
        }
    }
    
    printf("%lld\n", V - dp[V]);

    return 0;
}