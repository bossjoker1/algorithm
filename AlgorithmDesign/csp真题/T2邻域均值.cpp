// 直接记忆化保存即可
// 二维bit属实大材小用
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

#define MAX_N (605*8)

int tree[MAX_N][MAX_N], n, L, r, t , temp, ans=0;;

// 单点修改 & 区间查询
void add(ll x, int y, ll z){ //将点(x, y)加上z
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
    n = read(), L = read(), r = read(), t = read();
    rep(i, 1, n){
        rep(j, 1, n){
            temp = read();
            add(i, j, temp);
        }
    }
    rep(i, 1, n){
        rep(j, 1, n){
            int sum = 0, cnt = 0;
            int x1 = (i - r >= 1 ? i - r : 1), y1 = (j - r >= 1 ? j - r : 1);
            int x2 = (i + r <= n ? i + r : n), y2 = (j + r <= n ? j + r : n);
            cnt = (x2 - x1 + 1) * (y2 - y1 + 1);
            sum = ask(x2, y2) + ask(x1, y1) - ask(x2, y1)  - ask(x1, y2);
            if(sum <= cnt * t) ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}