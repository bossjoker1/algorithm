// 还是得用动态建树
#include<iostream>
#include<vector>
#include<string.h>
#include<map>
#include<algorithm>
#include<math.h>
#include <assert.h>
#include<queue>
#include<set>
#define INF 1000000000
#define p(x) x%3
#define MOD 1000000007
using namespace std;
#define maxn 100000000
using LL=long long int;
LL lazyx[maxn],lazyy[maxn],lazyz[maxn],lazymul[maxn],
lazyro[maxn],sum_x[maxn],sum_y[maxn],sum_z[maxn],lson[maxn],rson[maxn];
LL cnt=0;
inline void swap(LL& a,LL& b)
{
    LL t=a;
    a=b;
    b=t;
}
inline void pushdown(LL p,LL l,LL r)
{
    if(l==r)
    {
        lazyx[p] = lazyy[p] = lazyz[p] = lazymul[p] = lazyro[p] = 0;
        return;
    }
    LL& lchild = lson[p];
    LL& rchild = rson[p];
    if(!lchild)lchild=++cnt;
    if(!rchild)rchild=++cnt;
    LL mid = (l+r)>>1;
    if(!lazymul[p])lazymul[p] = 1;
    sum_x[lchild] =(sum_x[lchild]*(lazymul[p]%MOD)%MOD+((mid-l+1)%MOD)*(lazyx[p]%MOD)%MOD)%MOD,
    sum_x[rchild] =(sum_x[rchild]*(lazymul[p]%MOD)%MOD+((r-mid)%MOD)*(lazyx[p]%MOD)%MOD)%MOD;
    sum_y[lchild] =(sum_y[lchild]*(lazymul[p]%MOD)%MOD+((mid-l+1)%MOD)*(lazyy[p]%MOD)%MOD)%MOD,
    sum_y[rchild] =(sum_y[rchild]*(lazymul[p]%MOD)%MOD+((r-mid)%MOD)*(lazyy[p]%MOD)%MOD)%MOD;
    sum_z[lchild] =(sum_z[lchild]*(lazymul[p]%MOD)%MOD+((mid-l+1)%MOD)*(lazyz[p]%MOD)%MOD)%MOD,
    sum_z[rchild] =(sum_z[rchild]*(lazymul[p]%MOD)%MOD+((r-mid)%MOD)*(lazyz[p]%MOD)%MOD)%MOD;

    for(LL i=0;i<lazyro[p];++i)
    {
        swap(sum_x[lchild],sum_y[lchild]);
        swap(sum_y[lchild],sum_z[lchild]);
        swap(sum_x[rchild],sum_y[rchild]);
        swap(sum_y[rchild],sum_z[rchild]);
    }

    int u,v,w;

    u=lazyx[p],v=lazyy[p],w=lazyz[p];
    for(int i=0;i<lazyro[lchild];++i)
    {
        swap(v,w);
        swap(u,v);
    }

    lazyx[lchild] =(lazyx[lchild]*(lazymul[p]%MOD)%MOD+u%MOD)%MOD,
    lazyy[lchild] =(lazyy[lchild]*(lazymul[p]%MOD)%MOD+v%MOD)%MOD,
    lazyz[lchild] =(lazyz[lchild]*(lazymul[p]%MOD)%MOD+w%MOD)%MOD;

    u=lazyx[p],v=lazyy[p],w=lazyz[p];
    for(int i=0;i<lazyro[rchild];++i)
    {
        swap(v,w);
        swap(u,v);
    }
    lazyx[rchild] =(lazyx[rchild]*(lazymul[p]%MOD)%MOD+u%MOD)%MOD,
    lazyy[rchild] =(lazyy[rchild]*(lazymul[p]%MOD)%MOD+v%MOD)%MOD,
    lazyz[rchild] =(lazyz[rchild]*(lazymul[p]%MOD)%MOD+w%MOD)%MOD;


    if(lazymul[p]!=1)
    {
        if(!lazymul[lchild])
            lazymul[lchild]=1;
        lazymul[lchild] = lazymul[lchild]*(lazymul[p]%MOD)%MOD;
        if(!lazymul[rchild])
            lazymul[rchild]=1;
        lazymul[rchild] = lazymul[rchild]*(lazymul[p]%MOD)%MOD;
    }

    lazyro[lchild] = (lazyro[lchild] + lazyro[p])%3;
    lazyro[rchild] = (lazyro[rchild] + lazyro[p])%3;
    lazyx[p]=0;
    lazyy[p]=0;
    lazyz[p]=0;
    lazymul[p]=0;
    lazyro[p]=0;
}
void add(LL& p,LL l,LL r,LL L,LL R,LL a,LL b,LL c)
{
    if(!p)
    {
        p=++cnt;
    }
    if(r<L || l>R)
        return;

    if(l>=L && r<=R)
    {
        sum_x[p] =(sum_x[p]+(r-l+1)%MOD*(a%MOD)%MOD)%MOD,
        sum_y[p] =(sum_y[p]+(r-l+1)%MOD*(b%MOD)%MOD)%MOD,
        sum_z[p] =(sum_z[p]+(r-l+1)%MOD*(c%MOD)%MOD)%MOD;
        for(int i=0;i<lazyro[p];++i)
        {
            swap(b,c);
            swap(a,b);
        }
        lazyx[p] =(lazyx[p]+a%MOD)%MOD;
        lazyy[p] =(lazyy[p]+b%MOD)%MOD;
        lazyz[p] =(lazyz[p]+c%MOD)%MOD;
        return;
    }
    if(lazyx[p]||lazyy[p]||lazyz[p]||lazymul[p]||lazyro[p])
        pushdown(p,l,r);
    LL mid = (l+r)>>1;
    if(mid>=L)
        add(lson[p],l,mid,L,R,a,b,c);
    if(mid<R) 
        add(rson[p],mid+1,r,L,R,a,b,c);
    sum_x[p]=(sum_x[lson[p]]%MOD+sum_x[rson[p]]%MOD)%MOD;
    sum_y[p]=(sum_y[lson[p]]%MOD+sum_y[rson[p]]%MOD)%MOD;
    sum_z[p]=(sum_z[lson[p]]%MOD+sum_z[rson[p]]%MOD)%MOD;
}

void mul(LL& p,LL l,LL r,LL L,LL R,LL k)
{
    if(!p)
    {
        p=++cnt;
    }
    if(r<L || l>R)
        return;
    if(l>=L && r<=R)
    {
        if(!lazymul[p])
            lazymul[p]=1;
        lazymul[p] = lazymul[p]*(k%MOD)%MOD;
        lazyx[p] = lazyx[p]*(k%MOD)%MOD,
        lazyy[p] = lazyy[p]*(k%MOD)%MOD,
        lazyz[p] = lazyz[p]*(k%MOD)%MOD;
        sum_x[p] = sum_x[p]*(k%MOD)%MOD,
        sum_y[p] = sum_y[p]*(k%MOD)%MOD,
        sum_z[p] = sum_z[p]*(k%MOD)%MOD;
        return;
    }
    if(lazyx[p]||lazyy[p]||lazyz[p]||lazymul[p]||lazyro[p])
        pushdown(p,l,r);
    LL mid = (l+r)>>1;
    if(mid>=L)
        mul(lson[p],l,mid,L,R,k);
    if(mid<R) 
        mul(rson[p],mid+1,r,L,R,k);
    sum_x[p]=(sum_x[lson[p]]%MOD+sum_x[rson[p]]%MOD)%MOD;
    sum_y[p]=(sum_y[lson[p]]%MOD+sum_y[rson[p]]%MOD)%MOD;
    sum_z[p]=(sum_z[lson[p]]%MOD+sum_z[rson[p]]%MOD)%MOD;
}

void rotate(LL& p,LL l,LL r,LL L,LL R)
{
    if(!p)
    {
        p=++cnt;
    }
    if(r<L || l>R)
    return;
    if(l>=L && r<=R)
    {
        lazyro[p]++;
        lazyro[p]%=3;
        swap(sum_x[p],sum_y[p]);
        swap(sum_y[p],sum_z[p]);
        return;
    }
    if(lazyx[p]||lazyy[p]||lazyz[p]||lazymul[p]||lazyro[p])
        pushdown(p,l,r);
    LL mid = (l+r)>>1;
    if(mid>=L)
        rotate(lson[p],l,mid,L,R);
    if(mid<R)
        rotate(rson[p],mid+1,r,L,R);
    sum_x[p]=(sum_x[lson[p]]%MOD+sum_x[rson[p]]%MOD)%MOD;
    sum_y[p]=(sum_y[lson[p]]%MOD+sum_y[rson[p]]%MOD)%MOD;
    sum_z[p]=(sum_z[lson[p]]%MOD+sum_z[rson[p]]%MOD)%MOD;
}

void query(LL& p,LL l,LL r,LL L,LL R,LL& a,LL& b,LL& c)
{
    if(!p)
    {
        p=++cnt;
    }
    if(r<L || l>R)
        return;
    if(l>=L && r<=R)
    {
        a = (a+sum_x[p]%MOD)%MOD,
        b = (b+sum_y[p]%MOD)%MOD,
        c = (c+sum_z[p]%MOD)%MOD;
        return;
    }
    if(lazyx[p]||lazyy[p]||lazyz[p]||lazymul[p]||lazyro[p])
        pushdown(p,l,r);
    LL mid = (l+r)>>1;
    if(mid>=L)
        query(lson[p],l,mid,L,R,a,b,c);
    if(mid<R)
        query(rson[p],mid+1,r,L,R,a,b,c);
}

int main()
{
    LL n,m;cin>>n>>m;
    LL l=1,r=n;
    LL root=++cnt;
    for(LL i=0;i<m;++i)
    {
        LL option;cin>>option;
        LL L,R;cin>>L>>R;
        switch (option)
        {
        case 1:
            LL a,b,c;cin>>a>>b>>c;
            add(root,l,r,L,R,a,b,c);
            break;
        case 2:
            LL k;cin>>k;
            mul(root,l,r,L,R,k);
            break;
        case 3:
            rotate(root,l,r,L,R);
            break;
        case 4:
            LL f=0,d=0,e=0;
            query(root,l,r,L,R,f,d,e);
            cout<<((f%MOD)*(f%MOD)%MOD+(d%MOD)*(d%MOD)%MOD+(e%MOD)*(e%MOD)%MOD)%MOD<<endl;
            break;
        }
    }
    return 0;
}
