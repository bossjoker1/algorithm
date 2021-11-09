#include<bits/stdc++.h>
using namespace std;
const int N=105;
double a[N][N];
double x[N], eps=1e-7;
int solve(int n, int m){
    int c=0;
    int r;
    for(r=0;r<n&&c<m;r++,c++){
        int maxr=r;
        for(int i=r+1;i<n;i++){
            if(abs(a[i][c])>abs(a[maxr][c]))
                maxr=i;
        }
        if(maxr!=r) swap(a[r], a[maxr]);
        if(fabs(a[r][c])<eps){
            r--;
            continue;
        }
        for(int i=r+1;i<n;i++){
            if(fabs(a[i][c])>eps){
                double k=a[i][c]/a[r][c];
                for(int j=c;j<m+1;j++) a[i][j]-=a[r][j]*k;
                a[i][c]=0;
            }
        }
    } 
    for(int i=r;i<m;i++){
    	if(fabs(a[i][c])>eps) return -1;//无解
    }    
    if(r<m) return m-r;//返回自由元个数
    for(int i=m-1;i>=0;i--){
        for(int j=i+1;j<m;j++) a[i][m]-=a[i][j]*x[j];
        x[i]=a[i][m]/a[i][i];
    }
    return 0;//有唯一解
}
int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++) {
		for(int j=0;j<=n;j++) {
			cin>>a[i][j];
		}
	}
	int pan=solve(n, n);
	if(pan!=0) {
		cout<<"No Solution";
		return 0;
	}
	for(int i=0;i<n;i++) {
		printf("%.4lf\n", x[i]);
	}
}