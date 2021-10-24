// 主要还是贪心的思路
#include <stdio.h>
#include <string.h>
using namespace std;
 
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)
 
typedef long long ll;
 
 
inline int read(){
    int x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}

int dp[100005], d[100005];
 
int main(){
    int n = read();
    rep(i, 1, n){
        d[i] = read();
    }
    ll cnt = 0;
    rep(i, 1, n){
        cnt += d[i] > d[i-1] ? d[i] - d[i-1] : 0; 
    }
    printf("%lld\n", cnt);
    return 0;
}