#include <bits/stdc++.h>
using namespace std;
const int N=401000;
struct splay_tree
{
    int ff,cnt,ch[2],val,size;
} t[N];
int root,tot;
void update(int x)
{
    t[x].size=t[t[x].ch[0]].size+t[t[x].ch[1]].size+t[x].cnt;
}
void rotate(int x)
{
    int y=t[x].ff;
    int z=t[y].ff;
    int k=(t[y].ch[1]==x);
    t[z].ch[(t[z].ch[1]==y)]=x;
    t[x].ff=z;
    t[y].ch[k]=t[x].ch[k^1];
    t[t[x].ch[k^1]].ff=y;
    t[x].ch[k^1]=y;
    t[y].ff=x;
    update(y);update(x);
}
void splay(int x,int s)
{
    while(t[x].ff!=s)
    {
        int y=t[x].ff,z=t[y].ff;
        if (z!=s)
            (t[z].ch[0]==y)^(t[y].ch[0]==x)?rotate(x):rotate(y);
        rotate(x);
    }
    if (s==0)
        root=x;
}
void find(int x)
{
    int u=root;
    if (!u)
        return ;
    while(t[u].ch[x>t[u].val] && x!=t[u].val)
        u=t[u].ch[x>t[u].val];
    splay(u,0);
}
void insert(int x)
{
    int u=root,ff=0;
    while(u && t[u].val!=x)
    {
        ff=u;
        u=t[u].ch[x>t[u].val];
    }
    if (u)
        t[u].cnt++;
    else
    {
        u=++tot;
        if (ff)
            t[ff].ch[x>t[ff].val]=u;
        t[u].ch[0]=t[u].ch[1]=0;
        t[tot].ff=ff;
        t[tot].val=x;
        t[tot].cnt=1;
        t[tot].size=1;
    }
    splay(u,0);
}
int Next(int x,int f)
{
    find(x);
    int u=root;
    if (t[u].val>x && f)
        return u;
    if (t[u].val<x && !f)
        return u;
    u=t[u].ch[f];
    while(t[u].ch[f^1])
        u=t[u].ch[f^1];
    return u;
}
void Delete(int x)
{
    int last=Next(x,0);
    int Net=Next(x,1);
    splay(last,0);
    splay(Net,last);
    int del=t[Net].ch[0];
    if (t[del].cnt>1)
    {
        t[del].cnt--;
        splay(del,0);
    }
    else
        t[Net].ch[0]=0;
}
int kth(int x)
{
    int u=root;
    while(t[u].size<x)
        return 0;
    while(1)
    {
        int y=t[u].ch[0];
        if (x>t[y].size+t[u].cnt)
        {
            x-=t[y].size+t[u].cnt;
            u=t[u].ch[1];
        }
        else if (t[y].size>=x)
            u=y;
        else
            return t[u].val;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    insert(1e9);
    insert(-1e9);
    while(n--)
    {
        // 板子稍微改改就过了
        int opt,x;
        scanf("%d%d",&opt,&x);
        if (opt==1)
            insert(x);
        if (opt==2)
            Delete(kth(x+1));
        if (opt==3)
            printf("%d\n",kth(x+1));
    }
    return 0;
}


