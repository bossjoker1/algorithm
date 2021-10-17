#include<cstdio>
#include<algorithm>
using namespace std;
// q存索引 q2存值
int n,W,ans,head,tail,q[40010],q2[40010],dp[40010];
int main(){
	scanf("%d%d",&n,&W);
	for(int i=1;i<=n;i++){
		int v,w,c;
		scanf("%d%d%d",&v,&w,&c);
		if(v==0){
            // 保存些奇怪的输入带来的值
			ans+=v*c;
			continue;
		}
		int k=W/w;
		c=min(c,k); // 需要遍历的最小值
        // 枚举余数
		for(int d=0;d<w;d++){
			head=tail=0;
			k=(W-d)/w;
			for(int j=0;j<=k;j++){
				while(head<tail&&dp[d+j*w]-j*v>=q2[tail-1])
					tail--; // 队尾插入，去除冗余情况
				q[tail]=j;
				q2[tail++]=dp[d+j*w]-j*v;
				while(head<tail&&q[head]<j-c)
					++head; // 此时已是队首，前面的丢弃
				dp[d+j*w]=max(dp[d+j*w],q2[head]+j*v);
			}
		}
	}
	printf("%d",ans+dp[W]);
	return 0;
}