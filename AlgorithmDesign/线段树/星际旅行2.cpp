#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#define ll long long
#define clr(x) memset(x,0,sizeof(x))
#define INF 0x3fffffff
using namespace std;

inline int read()
{
	int ret=0,c=getchar(),b=1;
	while(!isdigit(c))c=='-'?b=-1:b=1,c=getchar();
	while(isdigit(c))ret=ret*10+c-'0',c=getchar();
	return ret*b;
}

#define M 100005
#define P 1000000007
#define fi (mo3(i+tree->fl))
#define for3 for(int i=0;i<3;i++)

struct tree2
{
	tree2 *lson,*rson;
	ll a[3];
	ll la[3],lm;
	int fl;
	tree2()
	{
		lm=1;
	}
}dizhi[M<<5],*root=&dizhi[0];

inline int mo3(int x)
{
	return x>=3?x-3:x;
}

inline void moc(ll &x,ll y)
{
	x=(x+y)%P;
}

int t;

void update(tree2 *tree)
{
	if(tree->lson==NULL)return ;
	for3 tree->a[i]=(tree->lson->a[i]+tree->rson->a[i])%P;
}

void pushdown(tree2 *tree,int l,int r)
{
	if(l==r)return ;
	int mid=(l+r)>>1;
	if(tree->lson==NULL)
	{
		tree->lson=&dizhi[++t];
		tree->rson=&dizhi[++t];
	}
	if(tree->fl)
	{
		ll temp[3];
		for3{temp[i]=tree->lson->a[i];}
		for3{tree->lson->a[i]=temp[mo3(tree->fl+i)];}
		for3{temp[i]=tree->lson->la[i];}
		for3{tree->lson->la[i]=temp[mo3(tree->fl+i)];}
		for3{temp[i]=tree->rson->a[i];}
		for3{tree->rson->a[i]=temp[mo3(tree->fl+i)];}
		for3{temp[i]=tree->rson->la[i];}
		for3{tree->rson->la[i]=temp[mo3(tree->fl+i)];}
		tree->lson->fl=mo3(tree->lson->fl+tree->fl);
		tree->rson->fl=mo3(tree->rson->fl+tree->fl);
		tree->fl=0;
	}
	tree->lson->lm=(tree->lson->lm*tree->lm)%P;
	tree->rson->lm=(tree->rson->lm*tree->lm)%P;
	for3
	{
		tree->lson->la[i]=(tree->lson->la[i]*tree->lm%P+tree->la[i])%P;
		tree->rson->la[i]=(tree->rson->la[i]*tree->lm%P+tree->la[i])%P;
		tree->lson->a[i]=(tree->lson->a[i]*tree->lm%P+tree->la[i]*(mid-l+1)%P)%P;
		tree->rson->a[i]=(tree->rson->a[i]*tree->lm%P+tree->la[i]*(r-mid)%P)%P;
		tree->la[i]=0;
	}
	tree->lm=1;
}

void change1(tree2 *tree,int l,int r,int x,int y,ll a[3])
{
	if(x<=l&&y>=r)
	{
		for3
		{
			moc(tree->la[i],a[i]);
			moc(tree->a[i],(r-l+1)*a[i]%P);
		}
		return ;	
	}
	int mid=(l+r)>>1;	
	pushdown(tree,l,r);
	if(x<=mid)change1(tree->lson,l,mid,x,y,a);
	if(y>mid)change1(tree->rson,mid+1,r,x,y,a);
	update(tree);
}

void change2(tree2 *tree,int l,int r,int x,int y,ll k)
{
	if(x<=l&&y>=r)
	{
		for3
		{
			tree->a[i]=tree->a[i]*k%P;
			tree->la[i]=tree->la[i]*k%P;
		}
		tree->lm=tree->lm*k%P;
		return ;
	}
	int mid=(l+r)>>1;
	pushdown(tree,l,r);
	if(x<=mid)change2(tree->lson,l,mid,x,y,k);
	if(y>mid)change2(tree->rson,mid+1,r,x,y,k);
	update(tree);
}

void change3(tree2 *tree,int l,int r,int x,int y)
{
	if(x<=l&&y>=r)
	{
		ll temp[3];
		for3{temp[i]=tree->a[i];}
		for3{tree->a[i]=temp[mo3(i+1)];}
		for3{temp[i]=tree->la[i];}
		for3{tree->la[i]=temp[mo3(i+1)];}
		tree->fl=mo3(tree->fl+1);
		return ;
	}
	int mid=(l+r)>>1;
	pushdown(tree,l,r);
	if(x<=mid)change3(tree->lson,l,mid,x,y);
	if(y>mid)change3(tree->rson,mid+1,r,x,y);
	update(tree);
}

void query(tree2 *tree,int l,int r,int x,int y,ll a[3])
{
	if(x<=l&&y>=r)
	{
		for3{moc(a[i],tree->a[i]);}
		return ;
	}
	int mid=(l+r)>>1;
	pushdown(tree,l,r);
	if(x<=mid)query(tree->lson,l,mid,x,y,a);
	if(y>mid)query(tree->rson,mid+1,r,x,y,a);
	update(tree);
}

int n,m;

int main()
{
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int t=read(),l=read(),r=read();
		ll a[3];
		if(t==1)
		{
			for3 a[i]=read();
			change1(root,1,n,l,r,a);
		}
		if(t==2)
		{
			ll k=read();
			change2(root,1,n,l,r,k);
		}
		if(t==3)
		{
			change3(root,1,n,l,r);
		}
		if(t==4)
		{
			clr(a);
			query(root,1,n,l,r,a);
			printf("%d\n",(a[0]*a[0]%P+a[1]*a[1]%P+a[2]*a[2]%P)%P);
		}
	}
	return 0;
}