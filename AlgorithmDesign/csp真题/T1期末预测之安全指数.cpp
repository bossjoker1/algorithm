#include <stdio.h>
#include <string.h>
 
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)
 
const int maxn = 100005;
 
inline int max(int x,int y){return x>y?x:y;}
 
inline int read(){
    int x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}

int n, w[maxn], s[maxn], sum = 0;

int main(){
    n = read();

    rep(i, 1, n){
        w[i] = read(), s[i] = read();
        sum += w[i] * s[i];
    }

    printf("%d\n", max(0, sum));


}