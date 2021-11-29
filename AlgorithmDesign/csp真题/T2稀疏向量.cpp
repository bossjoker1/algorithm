#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)

const int maxn = 100005;

inline int max(int x, int y) { return x > y ? x : y; }

inline int read() {
    int x = 0, f = 1; char ch = ' ';
    while (ch < '0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + (ch ^ 48); ch = getchar(); }
    return f == 1 ? x : -x;
}

map<int, int> mp1, mp2;

int n, a, b, d;

int main(){
    n = read(), a = read(), b = read();
    rep(i, 1, a){
        d = read();
        mp1[d] = read();
    }

    rep(i, 1, b){
        d = read();
        mp2[d] = read();
    }

    long long sum = 0;

    if(a<b){
        for(auto & t : mp1){
            sum += t.second * mp2[t.first];
        }
    }else{
        for(auto & t : mp2){
            sum += t.second * mp1[t.first];
        }
    }
    printf("%lld\n", sum);
    return 0;
}