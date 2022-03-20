#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<map>
#include<stack>
#include<queue>
#include<set>

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

// 结构体很重要
// 一开始把结构体确定了，后面直接a了
struct TaskNode {
	int id;
	int belong;
	set<int> apps;
	int taskLength;
}Nodes[1005];

struct AvailableArea
{
	set<int> taskFlags;
	TaskNode * tasknodes[1005];
	int nodeLength;
}AvailableAreas[1005];


ll N, M, g;


int main() {
	N = read(), M = read();
	int belong;
	rep(i, 1, N) {
		belong = read();
		Nodes[i].id = i, Nodes[i].belong = belong;
		AvailableAreas[belong].nodeLength++;
		AvailableAreas[belong].tasknodes[AvailableAreas[belong].nodeLength] = &Nodes[i];
		
	}
	int f, a, na, pa, paa, paar;
	g = read();

	rep(c, 1, g) {
		f = read(), a = read(), na = read(), pa = read(), paa = read(); paar = read();

		rep(i, 1, f) {
			if (pa == 0) {
				if (na != 0 and AvailableAreas[na].nodeLength == 0) {
					printf("0 ");
					continue;
				}
				int k = -1, minl = inf;
				if (na == 0) {
					rep(j, 1, N) {
						if (paa == 0 || Nodes[j].apps.find(paa) == Nodes[j].apps.end()) {
							if (Nodes[j].taskLength < minl) {
								k = j;
								minl = Nodes[j].taskLength;
							}
						}
					}
				}
				else {
					rep(j, 1, AvailableAreas[na].nodeLength) {
						if (paa == 0 || (*AvailableAreas[na].tasknodes[j]).apps.find(paa) == (*AvailableAreas[na].tasknodes[j]).apps.end()) {
							if ((*AvailableAreas[na].tasknodes[j]).taskLength < minl) {
								k = (*AvailableAreas[na].tasknodes[j]).id;
								minl = (*AvailableAreas[na].tasknodes[j]).taskLength;
							}
							else if ((*AvailableAreas[na].tasknodes[j]).taskLength == minl and (*AvailableAreas[na].tasknodes[j]).id < k) {
								k = (*AvailableAreas[na].tasknodes[j]).id;
							}
						}
					}
				}
				if (k != -1) {
					Nodes[k].taskLength++;
					Nodes[k].apps.insert(a);
					if (na == 0) {
						AvailableAreas[Nodes[k].belong].taskFlags.insert(a);
					}
					else {
						AvailableAreas[na].taskFlags.insert(a);
					}
					printf("%d ", k);
				}
				else if (paar == 0) {
					int k = -1, minl = inf;
					if (na == 0) {
						rep(j, 1, N) {
							if (Nodes[j].taskLength < minl) {
								k = j;
								minl = Nodes[j].taskLength;
							}
						}
					}
					else {
						rep(j, 1, AvailableAreas[na].nodeLength) {
							if ((*AvailableAreas[na].tasknodes[j]).taskLength < minl) {
								k = (*AvailableAreas[na].tasknodes[j]).id;
								minl = (*AvailableAreas[na].tasknodes[j]).taskLength;
							}
							else if ((*AvailableAreas[na].tasknodes[j]).taskLength == minl and (*AvailableAreas[na].tasknodes[j]).id < k) {
								k = (*AvailableAreas[na].tasknodes[j]).id;
							}
						}
					}
					Nodes[k].taskLength++;
					Nodes[k].apps.insert(a);
					if (na == 0) {
						AvailableAreas[Nodes[k].belong].taskFlags.insert(a);
					}
					else {
						AvailableAreas[na].taskFlags.insert(a);
					}
					printf("%d ", k);
					;
				}
				else {
					printf("0 ");
				}
			}
			else {
				if (na != 0 and AvailableAreas[na].nodeLength == 0) {
					printf("0 ");
					continue;
				}
				int k = -1, minl = inf;
				if (na == 0) {
					rep(j, 1, N) {
						if ((paa == 0 || Nodes[j].apps.find(paa) == Nodes[j].apps.end()) &&  AvailableAreas[Nodes[j].belong].taskFlags.find(pa) != AvailableAreas[Nodes[j].belong].taskFlags.end()) {
							if (Nodes[j].taskLength < minl) {
								k = j;
								minl = Nodes[j].taskLength;
							}
						}
					}
				}
				else {
					if (AvailableAreas[na].taskFlags.find(pa) != AvailableAreas[na].taskFlags.end()) {
						rep(j, 1, AvailableAreas[na].nodeLength) {
							if (paa == 0 || (*AvailableAreas[na].tasknodes[j]).apps.find(paa) == (*AvailableAreas[na].tasknodes[j]).apps.end()) {
								if ((*AvailableAreas[na].tasknodes[j]).taskLength < minl) {
									k = (*AvailableAreas[na].tasknodes[j]).id;
									minl = (*AvailableAreas[na].tasknodes[j]).taskLength;
								}
								else if ((*AvailableAreas[na].tasknodes[j]).taskLength == minl and (*AvailableAreas[na].tasknodes[j]).id < k) {
									k = (*AvailableAreas[na].tasknodes[j]).id;
								}
							}
						}
					}
				}
				if (k != -1) {
					Nodes[k].taskLength++;
					Nodes[k].apps.insert(a);
					if (na == 0) {
						AvailableAreas[Nodes[k].belong].taskFlags.insert(a);
					}
					else {
						AvailableAreas[na].taskFlags.insert(a);
					}
					printf("%d ", k);
				}
				else if (paar == 0) {
					int k = -1, minl = inf;
					if (na == 0) {
						rep(j, 1, N) {
							if (Nodes[j].taskLength < minl && AvailableAreas[Nodes[j].belong].taskFlags.find(pa) != AvailableAreas[Nodes[j].belong].taskFlags.end()) {
								k = j;
								minl = Nodes[j].taskLength;
							}
						}
					}
					else {
						rep(j, 1, AvailableAreas[na].nodeLength) {
							if (AvailableAreas[na].taskFlags.find(pa) != AvailableAreas[na].taskFlags.end()) {
								if ((*AvailableAreas[na].tasknodes[j]).taskLength < minl) {
									k = (*AvailableAreas[na].tasknodes[j]).id;
									minl = (*AvailableAreas[na].tasknodes[j]).taskLength;
								}
								else if ((*AvailableAreas[na].tasknodes[j]).taskLength == minl and (*AvailableAreas[na].tasknodes[j]).id < k) {
									k = (*AvailableAreas[na].tasknodes[j]).id;
								}
							}
						}
					}

					if (k == -1) {
						printf("0 ");
					}
					else {
						Nodes[k].taskLength++;
						Nodes[k].apps.insert(a);
						if (na == 0) {
							AvailableAreas[Nodes[k].belong].taskFlags.insert(a);
						}
						else {
							AvailableAreas[na].taskFlags.insert(a);
						}
						printf("%d ", k);
					}

				}
				else {
					printf("0 ");
				}
			}

			
		}

		printf("\n");
	}

	
	return 0;
}