// 静态区间查找最大值 O(1)
// 线段树只能做到O(logn)
// OI wiki 对应单元
// https://oi-wiki.org/ds/sparse-table/

#include <stdio.h>
#include <string.h>
 
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)

#define MAX_N 2000001
#define logn 21

typedef long long ll;

// f[i][j] [i, i+2^j-1]的最大值
int f[MAX_N][logn+1], LogN[MAX_N+1]; // 保存|_log_2(r-l+1)_| 直接math库计算非常耗时 
 
inline int max(int x,int y){return x>y?x:y;}
 
inline int read(){
    int x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}

inline void pre(){
    LogN[1] = 0;
    LogN[2] = 1;
    rep(i, 3, MAX_N){
        LogN[i] = LogN[i/2] + 1;
    }
}
 
int main(){
    pre();
    int n = read(), m = read();
    rep(i, 1, n) f[i][0] = read();
    // 构建ST表
    for(int j = 1;j<=logn;j++){
        for(int i = 1; i+(1<<j)-1 <= n; i++){
            f[i][j] = max(f[i][j-1], f[i + (1<<(j-1))][j-1]);
        }
    }
    int x, y, s;
    rep(i, 1, m){
        x = read(), y = read();
        s = LogN[y-x+1]; 
        printf("%d\n", max(f[x][s], f[y-(1<<s)+1][s]));
    }
    return 0;
}