#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
 
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)
 
typedef long long ll;
 
inline int max(int x,int y){return x>y?x:y;}
 
inline int read(){
    int x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}

int A[1000005], B[1000005], P[1000005];
// 默认按pair中的first排序
priority_queue <int,vector<pair<int, int>>,greater<pair<int, int>> > q;

int main(){
    int N = read();


    rep(i,1,N){
        A[i] = read();
    }
    rep(i,1,N){
        B[i] = read();
    }
    sort(A+1, A+N+1);
    sort(B+1, B+N+1);

    rep(i,1,N){
        q.push(make_pair(A[i] + B[1], i));
        P[i] = 1;
    }

    rep(k,1,N){
        pair<int, int> temp = q.top();
        q.pop();
        printf("%d ", temp.first);
        P[temp.second]++;
        q.push(make_pair(A[temp.second] + B[P[temp.second]], temp.second));
    }
    return 0;
}