// 只能过洛谷，过不了网安的oj
// 可能递归太深，爆栈了www
#include<cstdio>
#include<cstdlib>
#include <algorithm>
#define ll(x) (x<<1)
#define rr(x) (x<<1|1)
#define Mid(root) ((root->l + root->r)>>1)
using namespace std;
const int N=10000000+100;
typedef long long ll;

int n, m, cnt=0;

struct CPost{
    int L, R;
}posters[100100];

int x[200200]; // 存放所有海报的端点瓷砖的编号
int Nodehash[10000010]; // 离散化后的映射关系
struct CNode{
  int l, r;
  bool cover;
  CNode *pl, *pr;
}t[N];

int nodeCnt = 0; 

inline int read(){
  int ans = 0 , f = 1; char i=getchar();
  while(i<'0'||i>'9'){if(i=='-')f=-1;i=getchar();}
  while(i>='0'&&i<='9'){ans=ans*10+i-'0';i=getchar();}
  return ans * f;
}

void build(CNode* root,int l,int r){
  int mid = l+r>>1;
  root->l=l;
  root->r=r;
  root->cover=false;
  if(l == r){
    return;
  }
  nodeCnt++;
  root->pl = t + nodeCnt;
  nodeCnt++;
  root->pr = t + nodeCnt;
  build(root->pl, l, (l+r)>>1);
  build(root->pr, ((l+r)>>1)+1, r);
}

bool Post(CNode* root, int l, int r){
    if(root->cover) return false;
    if(root->l==l&&root->r==r){
        root->cover = true;
        return true;
    }

    bool res;
    int mid = (root->r+root->l) >> 1;
    if(r <= mid)
        res = Post(root->pl, l, r);
    else if(l >= mid+1)
        res = Post(root->pr, l, r);
    else{
        bool r1 = Post(root->pl, l, mid);
        bool r2 = Post(root->pr, mid+1, r);
        res = r1 || r2;
    }
    if(root->pl->cover && root->pr->cover)
        root->cover = true;
    return res;
}
 
int main(){
    n = read(), m = read();
    for(int i = 0; i < m; i++){
        posters[i].L = read(), posters[i].R = read();
        x[cnt++] = posters[i].L;
        x[cnt++] = posters[i].R;
    }
    // 离散化
    sort(x, x+cnt);
    int tot = unique(x, x+cnt) - x; 
    int no = 0;
    for(int i = 0; i < tot; i++){
        Nodehash[x[i]] = no;
        if(i < tot-1){
            if(x[i+1] - x[i] == 1)
                no ++;
            else
                no += 2;
        }
    }
    build(t, 0, no);
    int sum = 0;
    for(int i = m-1; i>=0; i--){
        if(Post(t, Nodehash[posters[i].L], Nodehash[posters[i].R])) sum++;
    }
    printf("%d\n", sum);
    return 0;
}

// 洛谷一个比较清晰的题解

#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=10000005,M=10005;

int n,m,Ans,A[M],B[M];
bool flag,colored[N<<2];

int read()
{
    int now=0;char c=getchar();
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')now=(now<<3)+(now<<1)+c-'0',c=getchar();
    return now;
}

void PushUp(int rt)
{
    colored[rt]= colored[rt<<1]&&colored[rt<<1|1];
}

/*void Build(int l,int r,int rt)
{
    if(l==r)
      return;
    int m=(l+r)>>1;
    Build(l,m,rt<<1);
    Build(m+1,r,rt<<1|1);
    PushUp(rt);
}*/

void Modify(int l,int r,int rt,int L,int R)
{
    if(colored[rt]) return;
    if(L<=l && r<=R)
    {
        flag=1;colored[rt]=1;
        return;
    }
    int m=(l+r)>>1;
    if(L<=m) Modify(l,m,rt<<1,L,R);
    if(m<R) Modify(m+1,r,rt<<1|1,L,R);
    PushUp(rt);
}

int main()
{
    n=read();m=read();
//    Build(1,n,1);
    for(int i=1;i<=m;i++)
      A[i]=read(),B[i]=read();
    for(int i=m;i>=1;i--)
    {
        flag=0;
        // 只要在modify中出现区间未染色，则可以看到
        Modify(1,n,1,A[i],B[i]);
        if(flag) ++Ans;
    }
    printf("%d",Ans);
    return 0;
}

// lower_bound()离散化，适用于浮点数或者N很大的时候

#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=10000005,M=100005;
/*struct node{//节约空间，可以把L,R放到参数里面，这样就只剩下covered了，直接放到数组 
	int L,R;
	int covered;
};*/
int n,m,flag,Ans,A[M],B[M],C[M<<1],covered[M<<3];//covered树变小了
void Update(int rt)
{
    covered[rt]= covered[rt<<1]&&covered[rt<<1|1];
}
/*void Build(int rt,int l,int r)//堆式存储，其实什么也没干 ，每个点的子节点是清楚的，直接省略 
{
    if(l==r)
      return;
    int m=(l+r)>>1;
    Build(rt<<1,l,m);
    Build(rt<<1|1,m+1,r);
    Update(rt);
}
*/
void Modify(int rt,int l,int r,int L,int R)
{
    if(covered[rt]) return;//如果L到R都被覆盖了，那么都会从这个地方返回，flag最终为0 
    if(L<=l && r<=R)//说明L,R区域中至少有一块没有被覆盖 
    {
        flag=1;covered[rt]=1;
        return;
    }
    int m=(l+r)>>1;
    if(L<=m) Modify(rt<<1,l,m,L,R);
    if(m<R) Modify(rt<<1|1,m+1,r,L,R);
    Update(rt);
}

int main()
{
    scanf("%d%d",&n,&m);
    //Build(1,1,n);
    for(int i=0;i<m;i++)
    {
      scanf("%d%d",A+i,B+i);
	  C[i<<1]=A[i];
	  C[i<<1|1]=B[i]+1; 
  	}
  	sort(C,C+(m<<1));
  	int ncount=unique(C,C+(m<<1))-C;
  	
    for(int i=m-1;i;i--)
    {
    	int L=lower_bound(C,C+ncount,A[i])-C+1;
		int R=lower_bound(C,C+ncount,B[i]+1)-C;
        flag=0;
        Modify(1,1,ncount+1,L,R);
        if(flag) ++Ans;
    }
    printf("%d",Ans);
    return 0;
}

// 动态建树法

#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=10000005,M=100005;
typedef struct node{
	int covered;
	struct node *lnode,*rnode; 
}Node;
int n,m,num,flag,Ans,A[M],B[M];
Node tree[M<<2];
void Update(Node * rt)
{
    rt->covered = rt->lnode->covered && rt->rnode->covered;
}
void Modify(Node *rt,int l,int r,int L,int R)
{
    if(rt->covered) return;
    if(L<=l && r<=R) 
    {
        flag=1;rt->covered=1;
        return;
    }
    if(rt->lnode==0)//和懒人标记一样，需要处理子节点的时候才创建，通常放在pushdown函数里面，和懒人标记一起处理 
    {
    	rt->lnode=tree+(++num);
    	rt->rnode=tree+(++num);
	}
    int m=(l+r)>>1;
    if(L<=m) Modify(rt->lnode,l,m,L,R);
    if(m<R) Modify(rt->rnode,m+1,r,L,R);
    Update(rt);
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
      scanf("%d%d",A+i,B+i);
	for(int i=m-1;i;i--)
    {
        flag=0;
        Modify(tree,1,n,A[i],B[i]);
        if(flag) ++Ans;
    }
    printf("%d",Ans);
    return 0;
}

