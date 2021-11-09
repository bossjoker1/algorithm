#include <stdio.h>
#include <string.h>
#include <iostream>
#include <set>
#include <map>
using namespace std;
 
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)
 
typedef long long ll;
 
inline ll max(ll x,ll y){return x>y?x:y;}
 
inline ll read(){
    ll x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}

// 变量字母部分
void statusA(string s, int p){
    if( 'a' <=s[p] <= 'z'){
        // 字母部分操作
        statusB(s, ++p);
    }
}

// 变量数字部分 0-99
void statusB(string s, int p){
    // 只有一位
    if(('0'<=s[p]&&s[p]<='9') &&(s[p]<'0'||s[p]>'9')) {
        // 操作

    }
    // 两位
    else if(('1'<=s[p]&&s[p]<='9') && ('0'<=s[p+1]&&s[p+1]<='9')){
        // 操作
        
    }
}
 
int main(){
    string s;
    while(cin>>s){

    }    
           
    return 0;
}