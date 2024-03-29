#include<bits/stdc++.h>
#include <stdio.h>
#include <string.h>
 
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)

#define MAXN 200005
 
typedef long long ll;
 
inline ll max(ll x,ll y){return x>y?x:y;}
 
inline ll read(){
    ll x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}

ll cun[MAXN], res = 0, n;
 
int main(){
    n = read();
    rep(i, 1, n){
        cun[i] = read();
    }

    rep(i, 2, n){
        res += max(cun[i], cun[i-1]);
    }
    printf("%lld\n", res);

    return 0;
}