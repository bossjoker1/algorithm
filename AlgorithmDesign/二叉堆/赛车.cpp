#include <stdio.h>
#include <string.h>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
 
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)

#define N 50005
 
typedef long long ll;
 
inline int max(int x,int y){return x>y?x:y;}
 
inline int read(){
    ll x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}

struct car{
	int x,y;
    double time;
	int p;//在堆中的位置 
}cars[N];

int heap[N]; //堆，记录bid 
int hc,bc;//堆的大小，建筑物的总数量
void Swap(int p,int q)
{
	swap(heap[p],heap[q]);
	cars[heap[p]].p=p;
	cars[heap[q]].p=q;
 } 
void Ins(int bdi)//插入第i号建筑物 
{
	heap[++hc]=bdi;cars[bdi].p=hc;
	int p=hc;double h=cars[bdi].time;
	while(p>1)
	{
		// 上浮
		if(h<cars[heap[p>>1]].time)
		{
			Swap(p,p>>1);p=p>>1;
		}
		else
			break;
	}
}
void Del(int bdi)//删除堆中的建筑物 
{
	int p=cars[bdi].p;
	Swap(p,hc--); // 先和最后一个元素换位置
	double h=cars[heap[p]].time;
	if(p>1 && p<=hc && h<cars[heap[p>>1]].time)//swim
		while(p>1)
		{
			if(h<cars[heap[p>>1]].time)
			{
				Swap(p,p>>1);p=p>>1;
			}
			else
				break;
		}
	else//sink
	{
		int q=p<<1;
		while(q<=hc)
		{
			if(q<hc && cars[heap[q+1]].time<cars[heap[q]].time)q++;
			if(cars[heap[q]].time>=h)break;
			Swap(p,q);p=q;q=p<<1;
		}
	}
 } 

int n, t, v[N],cur[N];


int main(){
    n = read(), t = read();
    // 看了下样例按xi顺序输入的
    // 第一辆车没有前置车
    rep(i, 1, n){
        cur[i] = read(), v[i] = read();
    }
    
    return 0;
}