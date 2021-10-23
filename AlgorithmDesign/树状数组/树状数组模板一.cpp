#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
 
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)

#define MAX_N (int)5e5

int bit[MAX_N+1], n;
 
inline int read(){
    int x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}


int sum(int i){
    int s = 0;
    while(i > 0){
        s += bit[i];
        i -= i & -i; //减去最尾端的1表示的幂
    }
    return s;
}

void add(int i, int x){
    while( i <= n){
        bit[i] += x;
        i += i & -i;
    } 
}

int main(){
    n = read();
    int m = read(), t;
    rep(i, 1, n){
        t = read();
        // 构建
        add(i, t);
    }
    int c, x, ky;
    rep(i, 1, m){
        c = read(), x = read(), ky = read();
        if(c == 1){
            add(x, ky);
        }else{
            printf("%d\n", sum(ky) - sum(x-1));
        }
    }

    return 0;
}