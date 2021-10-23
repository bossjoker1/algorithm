// 区间修改+单点查询
// 维护原数组i与i-1的差即可转化
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

void add(int i, int x){
    while( i <= n){
        bit[i] += x;
        i += i & -i;
    } 
}

void range_add(int l, int r, int x){ //给区间[l, r]加上x
    add(l, x), add(r + 1, -x);
}

int query(int i){
    int s = 0;
    while(i > 0){
        s += bit[i];
        i -= i & -i; //减去最尾端的1表示的幂
    }
    return s;
}

int main(){
    n = read();int m = read(), pre = 0, post;
    rep(i, 1, n){
        post = read();
        add(i, post - pre);
        pre = post;
    }

    rep(i, 1, m){
        int c = read();

        if(c == 1){
            int x = read(), y = read(), k = read();
            range_add(x, y, k);
        }else{
            int x = read();
            printf("%d\n",query(x));
        }
    }
    return 0;
}