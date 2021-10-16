#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string.h>
using namespace std;

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

int main(){
    ll W = read(), n = read();

    vector<ll> dp(W+1);

    map<int, vector<pair<ll, ll>>> mp;

    rep(i, 1, n){
        ll t1 = read(), t2 = read(), t3 = read();
        mp[t3].push_back(make_pair(t1, t2));
    }

    ll k = mp.size();

    rep(i, 1, k){
        rpe(v, W, 0){
            for(auto & item : mp[i]){ 
                if(v - item.first >= 0){
                    dp[v] = max(dp[v], dp[v - item.first] + item.second);
                }
            }
        }
    }

    printf("%lld\n", dp[W]);

    return 0;
}