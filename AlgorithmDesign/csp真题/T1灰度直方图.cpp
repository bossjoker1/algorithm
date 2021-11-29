#include <stdio.h>
#include <string.h>
 
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)
 
const int maxn = 505;
 
inline int max(int x,int y){return x>y?x:y;}
 
inline int read(){
    int x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}

int n, m, L, A[maxn][maxn], h[256];

int main(){
    n = read(), m = read(), L = read();

    rep(i, 0, n-1)
        rep(j, 0, m-1){
            A[i][j] = read();
            h[A[i][j]] ++;
        }

    rep(i, 0, L-1)
        printf("%d ", h[i]);
}