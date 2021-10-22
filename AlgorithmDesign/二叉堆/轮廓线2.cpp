#include<cstdio>
#include<algorithm>
#include<queue>   
using namespace std;
struct bd_tag{
	int x,h,y;
	int p;//�ڶ��е�λ�� 
}bd[1000005];
pair<int,pair<int,int> >event[2000005];//<x,bdi><y,bdi>,bdi��ʾ��������bd�е�λ�� 
int heap[1000005]; //�ѣ���¼bid 
int hc,bc;//�ѵĴ�С���������������
void Swap(int p,int q)
{
	swap(heap[p],heap[q]);
	bd[heap[p]].p=p;
	bd[heap[q]].p=q;
 } 
void Ins(int bdi)//�����i�Ž����� 
{
	heap[++hc]=bdi;bd[bdi].p=hc;
	int p=hc,h=bd[bdi].h;
	while(p>1)
	{
		// �ϸ�
		if(h>bd[heap[p>>1]].h)
		{
			Swap(p,p>>1);p=p>>1;
		}
		else
			break;
	}
}
void Del(int bdi)//ɾ�����еĽ����� 
{
	int p=bd[bdi].p;
	Swap(p,hc--); // �Ⱥ����һ��Ԫ�ػ�λ��
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
    	event[bc<<1]=make_pair(x,make_pair(bc,0));//0��߽�,���� 
    	event[(bc<<1)+1]=make_pair(y,make_pair(bc,1));//1�ұ߽� ���뿪 
    	bc++;
	}
	sort(event,event+(bc<<1));//���߽�����
	int nowx=0,nowh=0; 
	for(int i=0;i<(bc<<1);i++)//ɨ�� 
	{
		nowx=event[i].first;
		if(event[i].second.second==0)//�������� 
			Ins(event[i].second.first);
		else//������� 
			Del(event[i].second.first);
		if(i<(bc<<1)-1 && nowx==event[i+1].first)//ͬһ��x������ͳ�����¼� 
			continue;
		
		if(hc==0)//�ѱ���� 
			nowh=0;
		else if(bd[heap[1]].h!=nowh)
			nowh=bd[heap[1]].h;
		else
			continue;
		printf("%d %d ",nowx,nowh);
	 } 
    return 0;
}

