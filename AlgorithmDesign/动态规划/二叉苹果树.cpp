#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector <int> son[105];
int  n,q;
int f[105][105],val[105][105],vis[105];

void dfs(int x){
	vis[x]=1;//防止死循环做的标记		
	for(int i=0;i<son[x].size();i++){
		int ny=son[x][i];
		if(vis[ny]==1)	continue;//如果标记过则代表这是它的父节点，直接跳过
		vis[ny]=1;
		dfs(ny);
        // -1都是因为还包括自己和子节点连的一条边
		for(int j=q;j>=1;j--){
			for(int k=j-1;k>=0;k--){
				f[x][j]=max(f[x][j],val[x][ny]+f[ny][k]+f[x][j-k-1]); 
			}
		}
	}
}

int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<n;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		val[a][b]=c;//因为不知道关系存的两次价值（但只会用到一个）, 题目原因
		val[b][a]=c;
		son[a].push_back(b);
		son[b].push_back(a);
	}
	dfs(1);
	printf("%d",f[1][q]);
	return 0;
}