#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
 
using namespace std;
 
long long a[100005],b[100005];
 
struct tree
{
    int l,r,k;
};
 
struct tree d[400005];  int f[100005],h1,h2,n,d1,way[100005],ans[100005];
 
 
void buildtree(int l,int r,int k)
{
    d[k].l=l;
    d[k].r=r; d[k].k=0;
    if (l==r) return ;
    else
    {
        buildtree(l,(l+r)/2,k*2);
        buildtree((l+r)/2+1,r,k*2+1);
    }
}
 
int _count(long long low,long long high,int k)
{
    if (high<low) return 0;
    int t=(d[k].l+d[k].r)/2;
    if ((b[d[k].l]==low && b[d[k].r]==high) || (d[k].l==d[k].r)) return d[k].k;
    else if (high<=b[t]) return _count(low,high,k*2);
    else if (low>=b[t+1]) return _count(low,high,k*2+1);
    else
    {
        int h1=_count(low,b[t],k*2),h2=_count(b[t+1],high,k*2+1);
        if (f[h1]>f[h2]) return h1;
            else return h2;
    }
}
 
void find(int k,int p)
{
    if (d[k].l==d[k].r)
    {
        d[k].k=p;
        return ;
    }
    int t=(d[k].l+d[k].r)/2;
    if (a[p]<=b[t]) find(k*2,p);
    else find(k*2+1,p);
    if (f[p]>f[d[k].k]) d[k].k=p;
}
 
int main()
{
    scanf("%d%d",&n,&d1);
    for (int i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    int i=1,n1=1;
    while (i!=n+1)
    {
        while (b[i]==b[i+1]) i++;
        b[n1++]=b[i];
        i++;
    }
    n1--;
    //n1 is the length
    buildtree(1,n1,1);
    memset(way,0,sizeof(way));
    for (i=1;i<=n;i++)
    {
        h1=_count(b[1],a[i]-d1,1); h2=_count(a[i]+d1,b[n1],1);
        f[i]=max(f[h1],f[h2])+1;
        if (h1>=h2 && h1!=0) way[i]=h1;
        else if (h1<h2 && h2!=0) way[i]=h2;
        else way[i]=0;
        find(1,i);
    }
    i=1;
    int k=d[1].k; ans[i++]=k;
    printf("%d",f[k]);
    /*while (way[k]!=0)
    {
        ans[i++]=way[k];
        k=way[k];
    }
    for (int j=i-1;j>=1;j--) printf("%d ",ans[j]);*/ 
    return 0;
} 
