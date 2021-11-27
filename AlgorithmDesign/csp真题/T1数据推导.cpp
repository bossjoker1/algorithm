// 100
#include <stdio.h>
#include <string.h>
 
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)
 
const int maxn = 10005;
 
inline int max(int x,int y){return x>y?x:y;}
 
inline int read(){
    int x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}

int B[maxn], n, sum1 = 0, sum2 = 0;
 
int main(){  
    n = read();
    rep(i, 1, n){
        B[i] = read();
    }
    sum1 = sum2 = B[1];
    rep(i, 2, n){
        if(B[i] > B[i-1]){
            sum1 += B[i];
            sum2 += B[i];       
        }else{
            sum1 += B[i-1];
        }
    }

    printf("%d\n", sum1);
    printf("%d\n", sum2);

    return 0;
}