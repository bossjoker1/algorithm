#include <stdio.h>
# define min(x, y) (x)<(y)?(x):(y)
# define max(x, y) (x)<(y)?(y):(x)
//f[i][0]表示1-n的顺序第i个人为结尾的最长上升子序列 
//f[i][1]表示n-1的顺序第i个人为结尾的最长上升子序列 
int n,a[105],dp[105][2],ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    a[0]=0;
    //从1到n求最长上升序列 
    for(int i=1;i<=n;i++){
         for(int j=0;j<i;j++){
            if(a[i]>a[j]){
                //有取和不取两种状态 
                dp[i][0]=max(dp[i][0],dp[j][0]+1);
             }
         }
    } 
    a[n+1]=0;
    //从n到1求最长上升序列 
    for(int i=n;i;i--){
        for(int j=n+1;j>i;j--){
            if(a[i]>a[j]){
                dp[i][1]=max(dp[i][1],dp[j][1]+1);
            }
        }
    } 
    //枚举Ti，从1到Ti的最长升+从TK到Ti的最长升-1(因为Ti被加了两次)
    for(int i=1;i<=n;i++) {
        ans=max(dp[i][0]+dp[i][1]-1,ans);
    }    
    printf("%d\n",n-ans); 
    return 0;
}