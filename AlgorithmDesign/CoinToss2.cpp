// 能过的方法：
#include <stdio.h>
#include <string.h>
const int N = 105;
 
struct bign {
	int len, sex;
	int s[2000];
 
	bign() {
		this -> len = 1;
		this -> sex = 0;
		memset(s, 0, sizeof(s));
	}
 
	bign operator = (const char *number) {
		int begin = 0;
		len = 0;
		sex = 1;
		if (number[begin] == '-') {
			sex = -1;
			begin++;
		}
		else if (number[begin] == '+')
			begin++;
 
		for (int j = begin; number[j]; j++)
			s[len++] = number[j] - '0';
	}
 
	bign operator = (int number) {
		char string[N];
		sprintf(string, "%d", number);
		*this = string;
		return *this;
	}
 
	bign (int number) {*this = number;}
	bign (const char* number) {*this = number;}
 
	bign change(bign cur) {
		bign now;
		now = cur;
		for (int i = 0; i < cur.len; i++)
			now.s[i] = cur.s[cur.len - i - 1];
		return now;
	}
 
	void delZore() {	// 删除前导0.
		bign now = change(*this);
		while (now.s[now.len - 1] == 0 && now.len > 1) {
			now.len--;
		}
		*this = change(now);
	}
 
	void put() {    // 输出数值。
		delZore();
		if (sex < 0 && (len != 1 || s[0] != 0))
			printf("-");
		for (int i = 0; i < len; i++)
			printf("%d",s[i]);
	}
 
	bign operator + (const bign &cur){  
		bign sum, a, b;  
		sum.len = 0;
		a = a.change(*this);
		b = b.change(cur);
 
		for (int i = 0, g = 0; g || i < a.len || i < b.len; i++){  
			int x = g;  
			if (i < a.len) x += a.s[i];  
			if (i < b.len) x += b.s[i];  
			sum.s[sum.len++] = x % 10;  
			g = x / 10;  
		}  
		return sum.change(sum);  
	} 
 
	bign operator - (const bign &cur) {
		bign sum, a, b;
		sum.len = len;
		a = a.change(*this);
		b = b.change(cur);
 
		for (int i = 0; i < b.len; i++) {
			sum.s[i] = a.s[i] - b.s[i] + sum.s[i];
			if (sum.s[i] < 0) {
				sum.s[i] += 10;
				sum.s[i + 1]--;
			}
		}
		for (int i = b.len; i < a.len; i++) {
			sum.s[i] += a.s[i];
			if (sum.s[i] < 0) {
				sum.s[i] += 10;
				sum.s[i + 1]--;
			}
		}
		return sum.change(sum);
	}
};
 
bign c[N][N], sum[N], tmp = 1;
 
void init() {
	sum[0] = 1;
	for (int i = 1; i <= 100; i++)
		sum[i] = sum[i - 1] + sum[i - 1];
 
	for (int i = 0; i <= 100; i++)
		c[i][0] = c[0][i] = 1;
 
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			c[i][j] = c[i - 1][j] + c[i - 1][j];
			if (i == j + 1)
				c[i][j] = c[i][j] - tmp;
			else if (i > j + 1)
				c[i][j] = c[i][j] - c[i - j - 2][j];
		}
	}
}
 
int  main () {
	init();
	int n, k;
    // 输入为EOF时退出
	while (scanf("%d%d", &n, &k) == 2) {
		bign ans = sum[n] - c[n][k - 1];
		ans.put();
		printf("\n");
	}
	return 0;
}