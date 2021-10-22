// 还未过
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
 
inline int max(int x,int y){return x>y?x:y;}
 
inline int read(){
    int x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}

bool flag[1000000];
int a[1000000];
int num = 0;
//素数筛 Sieve of Eratosthenes，其时间复杂度的结论是O(N*loglogN)
void getPrime()
{
    memset(flag,0,sizeof(flag));
    for(int i = 2;i<=1000000;i++)
    {
        if(!flag[i])
        {
            //a存储素数因子
            a[num++] = i;
        }
        for(int j = 0;j<num;j++)
        {   
            //取当前已有的素数乘以系数i，这样可以避免取一个素数乘所有系数而导致的重复计算 (比如2*6和3*4就重复了
            if(a[j]*i>=100000)break;
            flag[a[j]*i] = true;
        }
    }
}
bool check(int x){
    int cnt = 0;
    // num 为当前素数表的个数
    for(int i = 0;i<num&&a[i]<x/a[i]&&cnt<=2;i++)
    {
        bool flag2 = false;
        //计算素因子，并且把当前素因子pi^β次方除尽后继续判断
        while(x%a[i]==0)
        {
            x/=a[i];
            flag2 = true;
        }
        if(flag2)cnt++;
    }
    if(x>1)cnt++;
    if(cnt==2)return true;
    else return false;
}
 
int main(){
    int m = read(), n = read();
    getPrime();
    rep(i, 0, m-1){
        printf("%d ", a[i]);
    }

           
    return 0;
}