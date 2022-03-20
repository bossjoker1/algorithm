#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<map>
#include<stack>
#include<queue>

using namespace std;


#define rep(i, l, r) for(int i=(l); i<=(r);i++)
#define rpe(i, r, l) for(int i=(r); i>=(l);i--)
#define inf 0x3f3f3f3f

typedef long long ll;
typedef pair<ll, ll> PLL;
typedef vector<ll> vec;

inline ll max(ll x, ll y) { return x > y ? x : y; }
inline ll min(ll x, ll y) { return x < y ? x : y; }

inline ll read() {
	ll x = 0, f = 1; char ch = ' ';
	while (ch < '0' || ch > '9') { if (ch == '-')f = -1; ch = getchar(); }
	while (ch >= '0' and ch <= '9') { x = x * 10 + (ch ^ 48); ch = getchar(); }
	return f == 1 ? x : -x;
}

ll N, M, k;

const ll MAXN = 100005;
int res = 0;

ll plan[MAXN][2];
int diff[500005];

 
// 差分，注意范围就能ac
int main() {
	N = read(), M = read() ,k = read();
	rep(i, 1, N) {
		plan[i][0] = read(), plan[i][1] = read();
		
		if (plan[i][0] - plan[i][1] > 0) {
			diff[plan[i][0] - plan[i][1]+1] += 1;
		}
		else {
			diff[0] += 1;
		}
		diff[plan[i][0]+1] -= 1;
	}

	int sum = 0, cur = 0, post;
	rep(i, 1, M) {
		post = read();
		post += k;
		while (cur <= post) {
			sum += diff[cur];
			cur++;
		}
		printf("%d\n", sum);
	}


	return 0;
}