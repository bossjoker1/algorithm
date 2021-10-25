// 带权并查集
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30000 + 5;
int _opt;
char _typ;
int f[MAXN], sum[MAXN], Size[MAXN];
//sum表示排名，即包括自己在内前面有多少人
//Size表示集合大小，即自己最后一次做祖先时集合内有多少人

int get(int k)
{
	if (f[k] == k) return k;
	int fake = f[k];  //当前祖先
	f[k] = get(f[k]);  //找祖先
	sum[k] += sum[fake] - 1;  //更新排名
	return f[k];
}

void merge(int a, int b)
{
	int f1 = get(a), f2 = get(b);
	sum[f1] = Size[f2] + 1;   //更新祖先排名，在get的时候pushdown到f1集合内的元素
	Size[f2] += Size[f1];  //更新祖先为f2的集合的大小
	f[f1] = f2;  // 更新所属祖先
}

int main()
{
	for (int i = 1; i <= MAXN; i++) f[i] = i, sum[i] = 1, Size[i] = 1;
	cin >> _opt;
	int a, b;
	while (_opt--)
	{
		cin >> _typ >> a >> b;
		if (_typ == 'M') merge(a, b);
		else
		{
			if (get(a) != get(b)) cout << "-1\n";
			else cout << abs(sum[a] - sum[b]) - 1 << endl;
		}
	}
	return 0;
}