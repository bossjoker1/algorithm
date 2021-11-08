#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define MAX 200000
inline int read()
{
    int x=0,t=1;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-')t=-1,ch=getchar();
    while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
    return x*t;
}
struct Node
{
    int ch[2];
    int ff,v;
    int size;
    int mark;
    void init(int x,int fa)
        {
            ff=ch[0]=ch[1]=0;
            size=1;v=x;ff=fa;
        }
}t[MAX];
int N,root,M,tot, ans[MAX];
inline void pushup(int x)
{
    t[x].size=t[t[x].ch[0]].size+t[t[x].ch[1]].size+1;
}
inline void pushdown(int x)
{
    if(t[x].mark)
    {
        t[t[x].ch[0]].mark^=1;
        t[t[x].ch[1]].mark^=1;
        t[x].mark=0;
        swap(t[x].ch[0],t[x].ch[1]);
    }
}

// int build_tree(int l, int r, int fa) {
//         if(l > r) { return 0; }
//         int mid = (l + r) >> 1;
//         int cur = ++tot;
//         t[cur].ff=fa;
// 	    t[cur].ch[0]=t[cur].ch[1]=0;
// 		// t[cur].cnt++;
//         // 原始数组ans
//     	t[cur].v=ans[mid];
// 		t[cur].size++;
//         t[cur].ch[0] = build_tree(l, mid - 1, cur);
//         t[cur].ch[1] = build_tree(mid + 1, r, cur);
//         pushup(cur);
//         return cur;
// }

inline void rotate(int x)
{
    int y=t[x].ff;
    int z=t[y].ff;
    int k=t[y].ch[1]==x;
    t[z].ch[t[z].ch[1]==y]=x;
    t[x].ff=z;
    t[y].ch[k]=t[x].ch[k^1];
    t[t[x].ch[k^1]].ff=y;
    t[x].ch[k^1]=y;
    t[y].ff=x;
    pushup(y);pushup(x);
}
inline void Splay(int x,int goal)
{
    while(t[x].ff!=goal)
    {
        int y=t[x].ff;int z=t[y].ff;
        if(z!=goal)
            (t[z].ch[1]==y)^(t[y].ch[1]==x)?rotate(x):rotate(y);
        rotate(x);
    }
    if(goal==0)root=x;
}
inline void insert(int x)
{
    int u=root,ff=0;
    while(u)ff=u,u=t[u].ch[x>t[u].v];
    u=++tot;
    if(ff)t[ff].ch[x>t[ff].v]=u;
    t[u].init(x,ff);
    Splay(u,0);
}
inline int Kth(int k)
{
    int u=root;
    while(1)
    {
        pushdown(u);
        if(t[t[u].ch[0]].size>=k)u=t[u].ch[0];
        else if(t[t[u].ch[0]].size+1==k)return u;
        else k-=t[t[u].ch[0]].size+1,u=t[u].ch[1];
    }
}

void InorderPrint(int u)
{
    pushdown(u);
    if(t[u].ch[0])InorderPrint(t[u].ch[0]);
    if(t[u].v>1&&t[u].v<N+2)printf("%d ",t[u].v-1);
    if(t[u].ch[1])InorderPrint(t[u].ch[1]);
}
inline void Reverse(int l,int r)
{
    l=Kth(l);
    r=Kth(r+2);
    Splay(l,0);
    Splay(r,l);
    t[t[t[root].ch[1]].ch[0]].mark^=1;
}
int main()
{
    N=read();M=read();
    for(int i=1;i<=N+2;++i)insert(i);
    while(M--)
    {
        int l=read(),r=read();
        Reverse(l,r);
    }
    InorderPrint(root);
    printf("\n");
    return 0;
}