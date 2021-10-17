#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
using namespace std;
 
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)
 
typedef long long ll;
 
inline int min(int x,int y){return x<y?x:y;}
 
inline int read(){
    int x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}

#define M 20123
 
int main(){

    int m = read();

    string s;

    rep(i, 1, m){

        getline(cin, s);

        int n = s.size(), res = 0, num = 0, cnt = 0, t;
        // cout<<"s.size: "<<n<<endl;
        rep(i, 0, n-1){
            t = s[i] - '0';
            // cnt 表前一个状态的1，2的个数，t是末位的值
            // 对个位，前面0~(num-1)共num个，每10个都有两个1，2
            res = (res-cnt)*10 + num*2 + cnt*(t+1) + min(t, 2);
            num = num*10 + t;
            if(t == 1|| t == 2) cnt++;
            num %= M;
            res %= M;
        }

        printf("%d\n", res);

    }
    return 0;
}