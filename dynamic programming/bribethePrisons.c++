//区间dp问题，同时要特别注意边界问题，这里采用人为添加左右两个无关边界
#include <iostream>
using namespace std;
const int INF=10000;
 
int P=20;
int Q=3;
int A[5]={0,3,6,14,21};
 
int dp[5][5];
 
void solve() {
    
    A[0]=0;
    A[Q+1]=P+1; //添加墙壁，由此可以包含所有囚徒
    
    
    for (int q=0;q<=Q;q++)
        dp[q][q+1]=0;//初始化，紧挨着的囚徒之间没有需要释放的囚徒
    
    for (int w=2; w<=Q+1;w++){
        for (int i=0; i+w<=Q+1;i++){
            //计算dp[i][j]
            int j=i+w, t=INF;
            
            for (int k=i+1;k<j;k++)
                t=min(t,dp[i][k]+dp[k][j]);
        
        
            dp[i][j]=t+A[j]-A[i]-2;
            
        }
            
    }
        
    
}
    

int main() {
    
    solve();
    cout<<dp[0][Q+1]<<endl;
    
}