#include<cstdio>
#include<algorithm>
#include<queue>   
using namespace std;
struct bd_tag{
	int x,h,y;
	int p;//在堆中的位置 
}bd[1000005];
pair<int,pair<int,int> >event[2000005];//<x,bdi><y,bdi>,bdi表示建筑物在bd中的位置 
int heap[1000005]; //堆，记录bid 
int hc,bc;//堆的大小，建筑物的总数量
void Swap(int p,int q)
{
	swap(heap[p],heap[q]);
	bd[heap[p]].p=p;
	bd[heap[q]].p=q;
 } 
void Ins(int bdi)//插入第i号建筑物 
{
	heap[++hc]=bdi;bd[bdi].p=hc;
	int p=hc,h=bd[bdi].h;
	while(p>1)
	{
		// 上浮
		if(h>bd[heap[p>>1]].h)
		{
			Swap(p,p>>1);p=p>>1;
		}
		else
			break;
	}
}
void Del(int bdi)//删除堆中的建筑物 
{
	int p=bd[bdi].p;
	Swap(p,hc--); // 先和最后一个元素换位置
	int h=bd[heap[p]].h;
	if(p>1 && p<=hc && h>bd[heap[p>>1]].h)//swim
		while(p>1)
		{
			if(h>bd[heap[p>>1]].h)
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
			if(q<hc && bd[heap[q+1]].h>bd[heap[q]].h)q++;
			if(bd[heap[q]].h<=h)break;
			Swap(p,q);p=q;q=p<<1;
		}
	}
 } 
int main()
{
	int x,h,y;
    while(scanf("%d%d%d",&x,&h,&y)!=EOF)
    {
    	bd[bc]={x,h,y,0};
    	event[bc<<1]=make_pair(x,make_pair(bc,0));//0左边界,进入 
    	event[(bc<<1)+1]=make_pair(y,make_pair(bc,1));//1右边界 ，离开 
    	bc++;
	}
	sort(event,event+(bc<<1));//按边界排序
	int nowx=0,nowh=0; 
	for(int i=0;i<(bc<<1);i++)//扫描 
	{
		nowx=event[i].first;
		if(event[i].second.second==0)//建筑物入 
			Ins(event[i].second.first);
		else//建筑物出 
			Del(event[i].second.first);
		if(i<(bc<<1)-1 && nowx==event[i+1].first)//同一个x发生入和出多个事件 
			continue;
		
		if(hc==0)//堆被清空 
			nowh=0;
		else if(bd[heap[1]].h!=nowh)
			nowh=bd[heap[1]].h;
		else
			continue;
		printf("%d %d ",nowx,nowh);
	 } 
    return 0;
}

