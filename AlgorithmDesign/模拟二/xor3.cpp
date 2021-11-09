#include <stdio.h>
#include <string.h>
#include <istream>
using namespace std;
 
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)
#define MOD 2021
typedef long long ll;

const int maxn = 3e5+10;
 
inline ll max(ll x,ll y){return x>y?x:y;}
 
inline ll read(){
    ll x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}

ll n, m, u1 = 2937228902, u2 = 862304001, ans[maxn];
int main(){
    n = read(), m = read();
    ll l, r;
    rep(i, 1, n) ans[i] = i;
    rep(i, 1, m){
        l = read(), r = read();
        ll sum = 0;
        rep(i, l, r) sum += (ans[i] % MOD);
        printf("%lld\n", sum);

        ll x = sum % 2 == 0 ? u1:u2;

        rep(i, l, r){
            ans[i] ^= x;
        }
    }
    return 0;
}