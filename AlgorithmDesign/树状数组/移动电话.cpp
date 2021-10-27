// 矩阵查询和单点修改
// 作区间查询的差即可
#include <stdio.h>
#include <string.h>
 
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)

#define MAX_N 1030

typedef long long ll;
 
inline ll max(ll x,ll y){return x>y?x:y;}
 
inline ll read(){
    ll x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}

ll tree[MAX_N][MAX_N], n;

void add(ll x, ll y, ll z){ //将点(x, y)加上z
    ll memo_y = y;
    while(x <= n){
        y = memo_y;
        while(y <= n)
            tree[x][y] += z, y += y & -y;
        x += x & -x;
    }
}

ll ask(ll x, ll y){//求左上角为(1,1)右下角为(x,y) 的矩阵和
    ll res = 0, memo_y = y;
    while(x){
        y = memo_y;
        while(y)
            res += tree[x][y], y -= y & -y;
        x -= x & -x;
    }
    return res;
}
 
int main(){
    read(), n = read();
    int c;
    while(1){
        scanf("%d", &c);
        if(c == 3) break;

        if(c == 1){
            ll x = read(), y = read(), a = read();
            add(x+1, y+1, a);
        }else{
            ll l = read(), b = read(), r = read(), t = read();
            printf("%lld\n", ask(r+1, t+1) - ask(l, t+1) - ask(r+1, b) + ask(l, b));
        }
    }
    return 0;
}