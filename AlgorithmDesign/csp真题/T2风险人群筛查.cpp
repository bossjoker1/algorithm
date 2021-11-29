#include<stdio.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)

const int maxn = 1005;

inline int max(int x, int y) { return x > y ? x : y; }

inline int read() {
    int x = 0, f = 1; char ch = ' ';
    while (ch < '0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + (ch ^ 48); ch = getchar(); }
    return f == 1 ? x : -x;
}


int n, k, t, xa, ya, xb, yb, cnt1 = 0, cnt2 = 0;

int main(){
    n = read(),k = read(),t = read(),xa = read(),ya = read(),xb = read(), yb = read();
    rep(i, 1, n){
        int count = 0, x, y;
        bool flag1 = false, flag2 = false;
        rep(j, 1, t){
            x = read(), y = read();
            if(x>=xa&&x<=xb&&y>=ya&&y<=yb){
                flag1 = true;
                count++;
            }else{
                count = 0;
            }
            if(count >= k){
                flag2 = true;
            }
        }

        if(flag1){
            cnt1++;
        }

        if(flag2){
            cnt2++;
        }
    }
    printf("%d\n", cnt1);
    printf("%d", cnt2);
    return 0;
}