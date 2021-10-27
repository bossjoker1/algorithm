// 区间查询 $ 区间修改
#include <stdio.h>
#include <string.h>

#define MAX_N 2505
 
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)
 
typedef unsigned int ui;
 
 
inline int read(){
    int x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}
int t1[MAX_N][MAX_N], t2[MAX_N][MAX_N], t3[MAX_N][MAX_N], t4[MAX_N][MAX_N], n;
ui ans, val;

void add(int x, int y, ui z){
    for(int X = x; X <= n; X += X & -X)
        for(int Y = y; Y <= n; Y += Y & -Y){
            t1[X][Y] ^= z;
            t2[X][Y] ^= ((x)&1)?z:0;
            t3[X][Y] ^= ((y)&1)?z:0;
            t4[X][Y] ^= ((x)&(y)&1)?z:0;
        }
}
void range_add(int xa, int ya, int xb, int yb, ui z){ //(xa, ya) 到 (xb, yb) 的矩形
    add(xa, ya, z);
    add(xa, yb + 1, z);
    add(xb + 1, ya, z);
    add(xb + 1, yb + 1, z);
}
ui ask(int x, int y){
    ui res = 0;
    for(int i = x; i; i -= i & -i)
        for(int j = y; j; j -= j & -j)
            res ^= (((x + 1)&(y + 1)&1)?t1[i][j]:0) ^ 
            (((y + 1)&1)?t2[i][j]:0) ^ 
            (((x + 1)&1)?t3[i][j]:0) ^ 
            t4[i][j];
    return res;
}
ui range_ask(int xa, int ya, int xb, int yb){
    return ask(xb, yb)^ask(xb, ya - 1)^ask(xa - 1, yb)^ask(xa - 1, ya - 1);
}
 
int main(){
    n = read();int m = read();
    char c;
    int x1, y1, x2, y2, K;
    rep(k, 1, m){
        scanf("%c", &c);
        if(c=='P'){
            x1 = read(), y1 = read(), x2 = read(), y2 = read();
            K = read();
            int a, b;
            val = 0;
            rep(k, 1, K){
                a = read(), b = read();
                if(b&1){
                    val^= (1<<a);
                }
            }
            range_add(x1, y1, x2, y2, val);

        }else{
            x1 = read(), y1 = read(), x2 = read(), y2 = read();
            ans = range_ask(x1, y1, x2, y2);
            rep(i, 1, 30){
                ans = ans >> 1;
                if(ans & 1){
                    printf("2");
                }else{
                    printf("1");
                }
            }
            printf("\n");
        }
    }       
           
    return 0;
}