// 总算能ac道树状数组的题目了
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

typedef long long ll;

#define MAX_N (int)1e5

ll bit1[MAX_N+5], bit2[MAX_N+5],a[MAX_N+5],n;
 
inline ll read(){
    int x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}


ll sum1(ll i){
    ll s = 0;
    while(i > 0){
        s += bit1[i];
        i -= i & -i; //减去最尾端的1表示的幂
    }
    return s;
}

ll sum2(ll i){
    ll s = 0;
    while(i > 0){
        s += bit2[i];
        i -= i & -i; //减去最尾端的1表示的幂
    }
    return s;
}

void add(ll i, ll x){
    ll ax = i*x;
    while( i <= n){
        bit1[i] += x;
        bit2[i] += ax;
        i += i & -i;
    } 
}

int main(){
    n = read();ll m = read();
    ll temp;
    rep(i, 1, n){
        temp = read();
        add(i, temp);
        a[i] = temp;
    }
    string c;
    rep(i, 1, m){
        cin>>c;
        if(c == "Modify"){
            // printf("modify\n");
            ll i = read(), x = read();
            ll d = x-a[i];
            a[i] = x;
            add(i, d);
        }else{
            ll p = read();
            ll s = (p+1)*sum1(p) - sum2(p);
            // printf("sum1: %d  sum2: %d\n", (p+1)*sum1(p), sum2(p));
            printf("%lld\n", s);
        }
    }

    return 0;
}