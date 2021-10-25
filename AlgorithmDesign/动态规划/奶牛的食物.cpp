// 状压dp
// F[i][k]+=F[i-1][j],表示第i行状态为k时的方案总数等于第i-1行状态为j时的方案总数之和,
// 其中状态k对于状态j而言是可行状态
#include<stdio.h>
using namespace std;
const int MOD=1e8;
int f[13][2100];//表示方案数 一行的方案不会超过2^6我觉得
int can[13];//最开始可以的（输入限制） 
int donot[201];//预处理行，表示合法的状态，大概不超过101个 


// 不相邻
bool judge(int x)
{
    return (x & (x>>1));
}
int main()
{
    int m,n; 
    scanf("%d%d",&m,&n);
    int x;
    int full=(1<<n)-1;//满状态 
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&x);
            if(!x) can[i]=can[i] | (1<<(n-j));
        }
    }
    int cnt=0;
    // 枚举每一种合法的状态
    for(int i=0;i<=full;i++)
    {
      if(judge(i)) continue;
      donot[++cnt]=i;
    }// 得到最后可行的状态数

    int last,now;
    // 第一行的初始情况，在这些不相邻可行状态中再筛选当前行能够放的
    for(int i=1;i<=cnt;i++)
    {
        now=donot[i];
        if(donot[i] & can[1]) continue;
        f[1][i]=1;
    }
    for(int i=2;i<=m;i++)
    {
        for(int j=1;j<=cnt;j++)
        {
            last=donot[j];//上个状态 
            if(last & can[i-1]) continue;
            for(int k=1;k<=cnt;k++)
            {
                now=donot[k];
                if(now & can[i]) continue;
                if(now & last) continue;
                f[i][k]+=f[i-1][j];
                f[i][k]%=MOD;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=cnt;i++) ans=(ans+f[m][i])%MOD;
    printf("%d",ans);
    return 0;
}