// 似乎是线段树的问题
// 看能不能套板子
// 似乎不太行
// 先去leetcode找几道线段树刷刷

#include <stdio.h>
#include <string.h>

#define rep(i,l,r) for(int i=(l);i<(r);++i)

typedef long long ll;

inline ll max(ll x,ll y){return x>y?x:y;}

inline ll read(){
    ll x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}


 
int main(){



    return 0;
}