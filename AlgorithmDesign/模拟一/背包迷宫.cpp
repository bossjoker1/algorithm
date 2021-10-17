#include <string.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)
 
inline int max(int x,int y){return x>y?x:y;}
 
inline int read(){
    int x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}

#define M 997

int main(){

    int col = read();

    int t1, t2, t3, t4, t5, t6, h1, h2, h3, h4, h5, h6;

    t1 = t2 = t3 = t4 = t6 = 1;
    t5 = 0;

    int j;
    rep(i, 2, col){
        h1 = t1, h2 = t2, h3 = t3, h4 = t4, h5 = t5, h6 = t6;
        t1 = h6 % M;
        t2 = (h6 + h3) % M;
        t3 = (h6 + h2) % M;
        t4 = (h6 + h5) % M;
        t5 = h4 % M;
        t6 = (h6 + h4 + h3 + h2 + h1) % M; 
    }

    printf("%d\n", t6);

    return 0;
}