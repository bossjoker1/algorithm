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

bool flag[2000000];
int a[2000000];
int num = 0;
//素数筛 Sieve of Eratosthenes，其时间复杂度的结论是O(N*loglogN)
// 生成的是小于2000000的素数集合
void getPrime()
{
    memset(flag,0,sizeof(flag));
    for(int i = 2;i<=2000000;i++)
    {
        if(!flag[i])
        {
            //a存储素数因子
            a[num++] = i;
        }
        for(int j = 0;j<num;j++)
        {   
            //取当前已有的素数乘以系数i，这样可以避免取一个素数乘所有系数而导致的重复计算 (比如2*6和3*4就重复了
            if(a[j]*i>=2000000)break;
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

struct myTuple{
    ll val, i, idx; 
};

bool operator< (myTuple m1, myTuple m2){
    return m1.val > m2.val; // 按val从小到大
}
 
int main(){
    int m = read(), n = read();
    getPrime(); // 获取素数表

    priority_queue<myTuple> q;

    rep(i, 0, m-1){
        q.push(myTuple{a[i], i, 0});
    }

    vector<ll> ans(n+1);

    ans[0] = 1;
    for(int j = 1; j <= n;){
        myTuple t = q.top();
        q.pop();
        if(t.val != ans[j-1]){
            ans[j++] = t.val;
            printf("%lld ", t.val);
        }
        q.push(myTuple{ans[t.idx+1]*a[t.i], t.i, t.idx+1});
    }
           
    return 0;
}