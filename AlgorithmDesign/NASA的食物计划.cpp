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

ll dp[405][405], v[55], w[55], ka[55];

int main(){
    ll V, W;
    V = read(), W = read();
    ll n = read();

    rep(i, 1, n){
        v[i] = read(), w[i] = read(), ka[i] = read();
    }

    rep(i, 1, n){
        rpe(j, V, v[i]){
            rpe(k, W, w[i]){
                dp[j][k] = max(dp[j][k], dp[j - v[i]][k - w[i]] + ka[i]);
            }
        }
    }
    printf("%lld\n", dp[V][W]);
}