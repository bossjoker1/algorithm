#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string.h>
#include <stack>
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

// dp[i][j]表示i~j形成的最大矩形

int largestRectangleArea(vector<int>& heights) {
    int len = heights.size();
    int area=0;
    //栈的目的:不用重复遍历所有匹配，查找可得左右边界情况
    stack<int> stk;//存储的是数组的索引值。单调栈，从底到顶，数字为从小到大
    stk.push(-1);
    int wide, height;
    int i=0;
    for(; i<len; ++i){//数组遍历（可能会计算之间部分面积）
    // 新添加元素小于或等于栈顶元素：栈顶元素为height的，矩形右边界能确定
        while(stk.top() !=-1 && heights[stk.top()]>=heights[i]){//符合条件面积都计算进去
            height = heights[stk.top()];stk.pop();
            wide = i - stk.top()-1;
            area = max(area, height*wide);
        }
    // 新元素大于栈顶元素：栈顶元素为height的矩形右边界没法确定。（直接入栈）
        stk.push(i);
    }

    while(stk.top() != -1){//再遍历栈中剩下的元素，栈中都是从小到大排列，计算面积就很有规律了
        height = heights[stk.top()];stk.pop();
        wide = len - stk.top()-1;
        area = max(area, height*wide);
    }
    return area;
}
 
int main(){
    ll n = read();
    vector<int> h(n);

    rep(i, 0, n-1){
        h[i] = read();
    }

    int res = largestRectangleArea(h);

    printf("%d\n", res);

    return 0;
}