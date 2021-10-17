// 嫖来的满分解
// 好家伙看都看不懂
// 先放这供着
#include<stdio.h>
#include<iostream>
using namespace std;
const int N=43,M=403;
int n,a[N][6],ans=1e9;
short f[M][M][M];
int p[5][3]={{2,2,2},{0,1,0}, {1,0,0},{0,3,3},{3,0,3}};

struct node{
    int c,x,y,z;
    node(int c=0,int x=0,int y=0,int z=0):c(c),x(x),y(y),z(z){}
}q[(int)7e4];

void work(){
    int cur,x,y,z,nows;int t=0;
//    unsigned short h=0,t=0;
    q[++t]=node(0,0,0,0);f[0][0][0]=-1;
//    while(h!=t){
    while(t>0){
//        node &ht=q[++h];
        node &ht=q[t--];
        cur=ht.c,x=ht.x,y=ht.y,z=ht.z;
        if(f[x][y][z]>=cur) continue;
        f[x][y][z]=cur;
        nows=max(x,max(y,z));
        if(nows>ans) continue;
        if(++cur==n+1){ans=min(ans,nows);continue;}
        for(int i=0;i<5;i++){
            q[++t]=node(cur,x+a[cur][p[i][0]],y+a[cur][p[i][1]],z+a[cur][p[i][2]]);
        }
    }
    printf("%d\n",ans);
}
//void dfs(int cur=0,int x=0,int y=0,int z=0){
//    auto &res=f[x][y][z];
//    if(res>=cur) return ;
//    res=cur;
//    int nows=max(x,max(y,z));
//    if(nows>=ans) return ;
//    if(cur==n){ans=min(ans,nows);return ;}
//    cur++;
//    for(int i=0;i<5;i++){
//        dfs(cur,x+a[cur][p[i][0]],y+a[cur][p[i][1]],z+a[cur][p[i][2]]);
//    }
//}
int main(){
//    freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=4;j++) cin>>a[i][j];
        if(a[i][2]>a[i][4]) a[i][2]=a[i][4];
    }
    work();
//    f[0][0][0]=-1;
//    dfs();printf("%d\n",ans);
    return 0;
}