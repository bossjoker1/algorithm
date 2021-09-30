// 暴力回溯，思路没问题，一个点过不了。。淦~
// 只能说比较好理解吧。。
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<(r);++i)

typedef long long ll;

inline ll max(ll x,ll y){return x>y?x:y;}

inline ll read(){
    ll x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}

vector<bool> status;
int d;
ll cnt;

void backTrack(int n, int flag, ll temp) {
    if (d == n) {
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!status[i]) {
            status[i] = true;
            if(flag == 0 && i+1 > temp){
                d++;
                backTrack(n, 1, i+1);
                d--;
            }

            else if(flag == 1 && i+1 < temp){
                d++;
                backTrack(n, 0, i+1);
                d--;
            }
            status[i] = false;
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);

    rep(i, 1, n+1){
        int num, p;
        cnt = 0, d = 0;
        num = read(), p = read();
        status.resize(p, false);
        if(p == 1) {
            printf("%d 1\n", i);
            continue;
        }
        backTrack(p, 0, -1);
        backTrack(p, 1, 1005);
        printf("%d %lld\n", i, cnt);
    }

    return 0;
}