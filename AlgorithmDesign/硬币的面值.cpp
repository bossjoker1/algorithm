// 给出面值，求最少的硬币个数满足所有不超过m的价格
// 贪心 + 动规的思想
// 先证明一下这一点：如果目前状态可取前 xxx 价格，且当前取了一个面额为 aaa 的硬币，要想构成前 x+ax + ax+a 的所有价格，必须仅当 x≥a−1x \ge a - 1x≥a−1 时成立--->

// 证：若 x<a−1x < a - 1x<a−1， 则我们取最小的 x+1x + 1x+1，它必须由 x+1−ax + 1 - ax+1−a 得到，而 x<a−1x < a - 1x<a−1,故 x+1−a<0x + 1 - a < 0x+1−a<0,由于不存在小于0的状态，故原命题成立。

// 假设当前状态，前 iii 种硬币已经用最小的硬币数 ansansans 构成最大的可行价格 tottottot ，那么如果当前 tot≥ai+1−1tot \ge a_{i + 1} - 1tot≥ai+1​−1，那么就可以直接 i++i + +i++；否则累加，使 tot=tot+aitot = tot + a_{i}tot=tot+ai​ 至 tot≥ai+1−1tot \ge a_{i + 1} - 1tot≥ai+1​−1 ， 同时每次 ansansans ++++++ 。因为我们在每一步都满足 tot≥ai+1−1tot \ge a_{i + 1} - 1tot≥ai+1​−1 ， 所以每次 i++i++i++ 时，我们都可以放心操作当前的 tot+aitot + a_{i}tot+ai​ 操作。特别的，当 iii 等于1时，如果 tot(=0)<a1−1tot(=0) < a_{1} - 1tot(=0)<a1​−1 , 即 a1>1a_{1} > 1a1​>1时，不能满足条件，因而无答案，这里解释了第二段的显然结论。

// 关于这个累加，由于数据范围很大，我们很容易被卡（如都是1），所以我们先算出 tottottot 加上多少个 aia_{i}ai​ 才能大于等于 ai+1a_{i + 1}ai+1​，即个数 k=(ai+1−2−tot)÷ai+1k = (a_{i + 1} - 2 - tot) \div a{i} + 1k=(ai+1​−2−tot)÷ai+1 ，再 tot=tot+k∗aitot = tot + k * a_{i}tot=tot+k∗ai​，ans=ans+kans = ans + kans=ans+k， 用 O（1）的时间解决了问题。同时我们把 an+1a_{n + 1}an+1​ 赋值为 mmm , 助于判停。

// 最后注意一点：如果 tottottot 刚好等于 m−1m - 1m−1 ，并结束了循环，此时我们要在循环外输出 ans+1ans + 1ans+1 , 以应对此特殊情况。

// 只能说碰到状态稍多的，就难地做出来了

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef vector<ll> vec;

// 快读
inline ll read(){
    ll x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}


ll n, m, a[2000005], ans, tot;

int main(){
	scanf("%lld%lld",&n,&m);
	for(int i = 1; i <= n; i++)
		a[i] = read();
	sort(a + 1, a + n + 1);
	if(a[1] != 1) {
		printf("No answer!!!\n");
		return 0;
	}
	a[n + 1] = m;
	for(int i = 1; i <= n; i++){
		if(tot < a[i + 1] - 1){
			ll k = (a[i + 1] - 2 - tot) / a[i] + 1;
			tot += a[i] * k;
			ans += k;
			if(tot >= m){
				printf("%lld\n",ans);
				return 0;
			}
		}
	}
	printf("%lld\n",ans + 1);
	return 0;
} 