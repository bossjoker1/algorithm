#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
const int mm=500010;
struct node
{
    int fa;
    int son[2];
    int val;///节点值
    int sz;///子树节点数
    int mx;///区间最大值，一个节点的区间是指以这个节点为根的子树的所有元素，所以不是固定的 
    int addtag;///区间增加
    bool revtag;///区间翻转
    bool sametag;///区间设置相同
    int sum;///区间和
    int qsum;///序列最大和
    int lsum;///左子树序列最大和
    int rsum;///右子树序列最大和
}tree[mm];//splay树 
int root,tot1;///tot1当前节点总数
int s[mm],tot2;///因删除而空闲的节点
int a[mm];///保存输入的原始数据
int n,q;
#define get(x) (tree[tree[x].fa].son[1]==(x))
#define Key_value tree[tree[root].son[1]].son[0]
#define t tree[x]
#define lson tree[x].son[0]
#define rson tree[x].son[1]
#define tlson tree[tree[x].son[0]]
#define trson tree[tree[x].son[1]]

void update(int x)//根据左右儿子的值update x节点，发生在左或者右儿子发生改变的时候 
{
    t.sz=tlson.sz+trson.sz+1;
    t.sum=tlson.sum+trson.sum+t.val;
    t.lsum=max(tlson.lsum,tlson.sum+t.val+max(0,trson.lsum));
    t.rsum=max(trson.rsum,trson.sum+t.val+max(0,tlson.rsum));
    t.qsum=max(0,tlson.rsum)+t.val+max(0,trson.lsum);
    t.qsum=max(t.qsum,max(tlson.qsum,trson.qsum));
    t.mx=max(t.val,tlson.mx);
    t.mx=max(t.mx,trson.mx);
}
void change_same(int x,int v)///标记当前节点x及其子节点设为相同的 V 值
{
    if(!x)return;
    t.val=t.mx=v;
    t.sum=v*t.sz;
    t.lsum=t.rsum=t.qsum=max(v,v*t.sz);
    t.sametag=1;///标记
}
void change_rev(int x)///标记当前节点x及其子节点逆转
{
    if(!x)return;
    swap(lson,rson);
    swap(t.lsum,t.rsum);
    t.revtag^=1;///标记
}
void change_add(int x,int tag)///标记当前节点x及其子节点增加tag
{
    if(!x)return;
    int ts=tag*t.sz;
    t.val+=tag;t.mx+=tag;t.addtag+=tag;
    t.sum+=ts;t.lsum+=ts;t.rsum+=ts;t.qsum+=ts;
}
void pushdown(int x)///已经访问节点x，将标记下传，下传前要计算当前标记对子节点的影响 
{
    if(t.sametag)
    {
        change_same(lson,t.val);
        change_same(rson,t.val);
        t.sametag=0;
    }
    if(t.revtag)
    {
        change_rev(lson);
        change_rev(rson);
        t.revtag=0;
    }
    if(t.addtag)
    {
        change_add(lson,t.addtag);
        change_add(rson,t.addtag);
        t.addtag=0;
    }
}

inline void Rotate(int x)
{
    int which=get(x);
    int y=tree[x].fa;
    int z=tree[y].fa;
    pushdown(y);
    pushdown(x);
    tree[y].son[which]=tree[x].son[which^1];
    tree[tree[y].son[which]].fa =y;
    tree[x].son[which^1]=y;
    tree[y].fa=x;
    tree[x].fa=z;
    if(z!=0)
    {
        tree[z].son[tree[z].son[1]==y]=x;
    }
    update(y);
    update(x);

}
inline void Splay(int x,int goal)///将当前节点转到目标goal之下,例如goal=0,则表示转为根
{
    int fa=tree[x].fa;
    while(fa!=goal)
    {
        if(tree[fa].fa!=goal)
            Rotate(get(x)==get(fa)?fa:x);
        Rotate(x);
        fa=tree[x].fa;
    }
    if(goal==0)root=x;
}
inline int Get_Kth(int x,int k)///得到当前节点下第k个数据在tree中的位置
{
    pushdown(x);
    int tt=tlson.sz+1;
    if(tt==k)return x;
    if(tt>k)return Get_Kth(lson,k);
    else return Get_Kth(rson,k-tt);
}
/***初始化***/
void NewNode(int &x,int fa,int v)///在节点father下新加一个值为v的节点，x返回该节点在tree数组中的位置
{
    if(tot2)x=s[tot2--];
    else x=++tot1;
    t.fa=fa;
    lson=rson=0;
    t.val=t.sum=t.mx=t.lsum=t.rsum=t.qsum=v;
    t.addtag=t.revtag=t.sametag=0;
    t.sz=1;
}
void Build(int &x, int l, int r, int fa) {
    if(l > r) return;
    int mid = (l + r)/2;
    NewNode(x,fa,a[mid]);
    Build(lson, l, mid - 1, x);
    Build(rson, mid + 1, r, x);
    update(x);
}
void Init()
{
    root=tot1=tot2=0;
    tree[0].mx=tree[0].lsum=tree[0].rsum=tree[0].qsum=-INF;   ///////////0/////////////
    NewNode(root,0, -1);                                      ///////////|/////////////
    NewNode(tree[root].son[1],root, -1);                    ///////////root(-1)/////////////
    for(int i=0;i<n;i++)scanf("%d",&a[i]);                  ///////////////\//////////
    Build(Key_value,0,n-1,tree[root].son[1]);            /////////////////son[1](-1)//////////
    update(tree[root].son[1]);                           ////////////////////////////////////
    update(root);                                        ////////////Key_value/////////////////
}
/****基本功能****/
///在第x个数后插入tot个数
void Insert(int x,int tot)
{
    for(int i=0;i<tot;i++)scanf("%d",&a[i]);
    Splay(Get_Kth(root,x+1),0);
    Splay(Get_Kth(root,x+2),root);
    Build(Key_value,0,tot-1,tree[root].son[1]);
    update(tree[root].son[1]);
    update(root);
}
void Erase(int x)
{
    if(!x)return;
    s[++tot2]=x;
    Erase(lson);
    Erase(rson);
}
///从第x个数开始连续删除tot个数
void Delete(int x,int tot)
{
    Splay(Get_Kth(root,x),0);
    Splay(Get_Kth(root,x+tot+1),root);
    Erase(Key_value);
    tree[Key_value].fa=0;
    Key_value=0;
    update(tree[root].son[1]);
    update(root);
}
///从第x个数连续开始的tot个数修改为c
void Make_Same(int x,int tot,int c)
{
    Splay(Get_Kth(root,x),0);
    Splay(Get_Kth(root,x+tot+1),root);
    change_same(Key_value,c);
    update(tree[root].son[1]);
    update(root);
}
///反转
void Reverse(int x,int tot)
{
    Splay(Get_Kth(root,x),0);
    Splay(Get_Kth(root,x+tot+1),root);
    change_rev(Key_value);
    update(tree[root].son[1]);
    update(root);
}
///求和
int Get_Sum(int x,int tot)
{
    Splay(Get_Kth(root,x),0);
    Splay(Get_Kth(root,x+tot+1),root);
    return tree[Key_value].sum;
}
///得到子序列最大和
int Get_MaxSum(int x,int tot)
{
    Splay(Get_Kth(root,x),0);
    Splay(Get_Kth(root,x+tot+1),root);
    return tree[Key_value].qsum;
}
/*
 返回x代表的区间的最大值 
int Get_Max(int x)
{
    return t.mx;
}
*/
//中序打印调试 
void Inorder(int x)
{
    if(!x)return;
    pushdown(x);
    Inorder(lson);
    printf("%d*%d ",t.val,t.qsum);
    Inorder(rson);
}
int main()
{
 
    scanf("%d%d",&n,&q);
    {
        Init();
        char op[20];
        int x,y,z;
        while(q--)
        {
            ///printf("\n");
            ///Inorder(root);
            scanf("%s",op);
            if(op[0]=='I')
            {
                scanf("%d%d",&x,&y);
                Insert(x,y);
            }
            else if(op[0]=='D')
            {
                scanf("%d%d",&x,&y);
                Delete(x,y);
            }
            else if(op[0]=='M'&&op[2]=='K')
            {
                scanf("%d%d%d",&x,&y,&z);
                Make_Same(x,y,z);
            }
            else if(op[0]=='R')
            {
                scanf("%d%d",&x,&y);
                Reverse(x,y);
            }
            else if(op[0]=='G')
            {
                scanf("%d%d",&x,&y);
                printf("%d\n",Get_Sum(x,y));
            }
            else
            {
                printf("%d\n",Get_MaxSum(1,tree[root].sz-2));
            }
        }
    }
    return 0;
}
