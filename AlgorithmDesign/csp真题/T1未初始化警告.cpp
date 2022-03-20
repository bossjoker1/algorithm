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

ll N, k;

ll MAXN = 100005;

int main() {
	N = read(), k = read();

	vec visited(N+1, 0);
	visited[0] = 1;
	int l, r;
	int res = 0;
	rep(i, 1, k) {
		l = read(), r = read();
		if (visited[r] == 0) {
			res++;
		}
		visited[l] = 1;
	}


	printf("%d\n", res);
	return 0;
}