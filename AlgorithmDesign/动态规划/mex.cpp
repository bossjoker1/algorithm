#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
long long a[200010], pos[200010], num[200010];
int main(){
	int n;
	while(scanf("%d", &n), n){
		memset(pos, 0, sizeof(pos));
		memset(num, 0, sizeof(num));
		for(int i=1; i<=n; i++)
			scanf("%lld", &a[i]);
		long long last, tmp, ans;
		tmp=ans=0;
		for(int i=1; i<=n; i++){
			if(a[i]<n){
				last=pos[a[i]];//last表示上一次a[i]的位置；
				pos[a[i]]=i;
				for(int j=a[i]; j<=n; j++){
					if(j) num[j]=min(num[j-1], pos[j]);
					else num[j]=i;
					if(num[j]>last){
						tmp+=(num[j]-last);
					}
					else break;
				}
			}
			ans+=tmp;
		}
		printf("%lld\n", ans);
	}
	return 0;
}