#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX=1e3+5;
int N,S,P,T;
double dt;
double u,v,a,b,c,d;
int rn,rns;
int maxd;
double maxv=-INF,minv=INF;
int maxtime=-INF,mintime=INF;
int r[MAX];
vector<int>G[MAX<<1]; //用vector容器存放节点连接情况
struct ce{
    double u,v,a,b,c,d;
    int time; //神经元发射脉冲的次数
}ces[MAX];
struct mc{
    int s,t;
    double w;
    int D;
}mcs[MAX];
 
 

static unsigned long next1 = 1;
 
/* RAND_MAX assumed to be 32767 */
int myrand(void) {
    next1 = next1 * 1103515245 + 12345;
    return((unsigned)(next1/65536) % 32768);
}
 
 
int main(){
    rns=0;
    cin>>N>>S>>P>>T;
    cin>>dt;
    while (rns<N) {
        cin>>rn>>v>>u>>a>>b>>c>>d;
        //更新的是每段时间的神经元信息
        for(int i=rns;i<rns+rn;i++)
        {
            ces[i].v=v;
            ces[i].u=u;
            ces[i].a=a;
            ces[i].b=b;
            ces[i].c=c;
            ces[i].d=d;
            ces[i].time=0;
        }
        rns+=rn;
    }
    for(int i=0;i<P;i++)
        cin>>r[i];
    for(int i=0;i<S;i++)
    {
        cin>>mcs[i].s>>mcs[i].t>>mcs[i].w>>mcs[i].D;
        maxd=max(maxd,mcs[i].D);
        G[mcs[i].s].push_back(i);//存放节点连接情况
    }
    int mod=maxd+1;
    vector<vector<double>> I(mod,vector<double>(N));
    for(int k=0;k<T;k++)
    {
        //Ik表示每时刻受到的脉冲之和 所以每次都要清零
        for(int i=0;i<N;i++)
            I[(k+maxd)%mod][i]=0;
        
        //脉冲过程的模拟
        for(int i=0;i<P;i++)
        {
            int my=myrand();
            if(r[i]>my){
                for(int j=0;j<G[N+i].size();j++) //传向连接的所有神经元
                {
                    mc m=mcs[G[N+i][j]];
                    I[(k+m.D)%mod][m.t]+=m.w;
                }
            }
        }
        
        for(int i=0;i<N;i++)
        {
            double v1=ces[i].v;
            double u1=ces[i].u;
            double a1=ces[i].a;
            double b1=ces[i].b;
            ces[i].v=v1+dt*(0.04*v1*v1+5*v1+140-u1)+I[k%mod][i];
            ces[i].u=u1+dt*a1*(b1*v1-u1);
            if(ces[i].v>=30){
                ces[i].time++;
                for(int j=0;j<G[i].size();j++)
                {
                    mc m=mcs[G[i][j]];
                    I[(k+m.D)%mod][m.t]+=m.w;
                }
                ces[i].v=ces[i].c;
                ces[i].u+=ces[i].d;
            }
        }
        
    }
    for(int i=0;i<N;i++)
    {
        maxv=max(maxv,ces[i].v);
        minv=min(minv,ces[i].v);
        maxtime=max(maxtime,ces[i].time);
        mintime=min(mintime,ces[i].time);
    }
    cout<<fixed<<setprecision(3)<<minv<<" "<<maxv<<endl;
    cout<<mintime<<" "<<maxtime<<endl;
    return 0;
}
