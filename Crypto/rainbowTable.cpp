#include<iostream>
#include<map>
#include<string.h>
using namespace std;

typedef long long ll;

inline ll read(){
    ll x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}

void getstr(unsigned n, char str[8])
{
	str[0] = 'a'; str[1] = '0'; str[2] = '0'; str[3] = '0'; str[4] = '0'; str[5] = '0'; str[6] = '0'; str[7] = '0';
	int i = 2;
	while (n)
	{
		unsigned tmp = n % 36;
		if (tmp < 10)
			str[i++] = tmp + '0';
		else
		{
			str[i++] = tmp - 10 + 'a';
		}
		n = n / 36;
	}
}

// R函数： 约简函数（reduction function）
// 它的值域和定义域与H函数相反。通过该函数可以将哈希值约简为一个与原文相同格式的值。

// 存储每条链的头尾节点
// 以大量的随机明文作为起节点，通过上述步骤计算出哈希链并将终节点进行储存，可得到一张哈希链集
// 彩虹表在各步的运算中，并不使用统一的R函数，而是分别使用R1…Rk共k个不同的R函数，以此来解决链重叠的问题
// 其在生成的过程中，针对的是特定的H函数，因此如果用户加了salt值，每个用户的H函数都不同。


inline void R(unsigned sha1[5], char str[8], int i)
{
	getstr((sha1[0] + sha1[1] * i) % 2176782336, str);
}

unsigned int SHA1_tmp;
// 移位操作
#define SHA1_ROTL(a,b) (SHA1_tmp=(a),((SHA1_tmp>>(32-b))&(0x7fffffff>>(31-b)))|(SHA1_tmp<<b))
// F函数
#define SHA1_F(B,C,D,t) ((t<40)?((t<20)?((B&C)|((~B)&D)):(B^C^D)):((t<60)?((B&C)|(B&D)|(C&D)):(B^C^D)))

inline int UnitSHA1(const char* str, int length, unsigned sha1[5]) {
	/*
	计算字符串SHA-1
	参数说明：
	str         字符串指针
	length      字符串长度
	sha1         用于保存SHA-1的字符串指针
	返回值为参数sha1
	*/
	unsigned char* pp, * ppend;
	unsigned int l, i, K[80], W[80], TEMP, A, B, C, D, E, H0, H1, H2, H3, H4;
	H0 = 0x67452301, H1 = 0xEFCDAB89, H2 = 0x98BADCFE, H3 = 0x10325476, H4 = 0xC3D2E1F0;
	for (i = 0; i < 20; K[i++] = 0x5A827999);
	for (i = 20; i < 40; K[i++] = 0x6ED9EBA1);
	for (i = 40; i < 60; K[i++] = 0x8F1BBCDC);
	for (i = 60; i < 80; K[i++] = 0xCA62C1D6);
	l = length + ((length % 64 > 56) ? (128 - length % 64) : (64 - length % 64));
	if (!(pp = (unsigned char*)malloc((unsigned int)l))) return -1;
	for (i = 0; i < length; pp[i + 3 - 2 * (i % 4)] = str[i], i++);
	for (pp[i + 3 - 2 * (i % 4)] = 128, i++; i < l; pp[i + 3 - 2 * (i % 4)] = 0, i++);
	*((unsigned int*)(pp + l - 4)) = length << 3;
	*((unsigned int*)(pp + l - 8)) = length >> 29;
	for (ppend = pp + l; pp < ppend; pp += 64) {
		for (i = 0; i < 16; W[i] = ((unsigned int*)pp)[i], i++);
		for (i = 16; i < 80; W[i] = SHA1_ROTL((W[i - 3] ^ W[i - 8] ^ W[i - 14] ^ W[i - 16]), 1), i++);
		A = H0, B = H1, C = H2, D = H3, E = H4;
		for (i = 0; i < 80; i++) {
			TEMP = SHA1_ROTL(A, 5) + SHA1_F(B, C, D, i) + E + W[i] + K[i];
			E = D, D = C, C = SHA1_ROTL(B, 30), B = A, A = TEMP;
		}
		H0 += A, H1 += B, H2 += C, H3 += D, H4 += E;
	}
	free(pp - l);
	sha1[0] = H0, sha1[1] = H1, sha1[2] = H2, sha1[3] = H3, sha1[4] = H4;
	return 0;
}

int m;
char startS[10001][9] = {0}, endS[10001][9] = {0};
map<string,int> mp;

unsigned sha1[5];

bool f = false;

int main(){

    // 读取输入

	char str[9] = {0};
	// 保存sha1中间结果
	unsigned temp[5];

    m = read();

    for (int i = 0; i < m; i++) {
		scanf("%s%s", startS[i], endS[i]);
		// 反过来存链尾的映射
		mp[endS[i]] = i;
	}

    // 待寻找的sha1口令
	scanf("%08x%8x%8x%8x%8x", &(sha1[0]), &(sha1[1]), &(sha1[2]), &(sha1[3]), &(sha1[4]));

	// 计数，防止出现可能错误的链尾
	int cnt;
	for(int i = 0; !f && i < 100; i++){
		memcpy(temp, sha1, sizeof(unsigned)*5);
		for(int j = 0; !f && j < 10000; j++){
			R(temp, str, (i + j) % 100 + 1);
			// 只有R100才可能是链尾，但存在可能的R100不是链尾的情况，
			// 此时我们只需对链头到该R100进行遍历
			// 对这种情况进行判断，可以省去不必要的10000次循环
			if(mp.find(str) != mp.end() && (i + j) % 100 == 99) {
				int nums = i+j;
				char tempStr[9];
				int flag = mp[str]; // 得到对应的链
				strcpy(tempStr, startS[flag]);
				for (int j = 0; j <= nums; j++) {
					UnitSHA1(tempStr, 8, temp);		// 得到sha1
					if (temp[0] == sha1[0] && temp[1] == sha1[1] && temp[2] == sha1[2] && temp[3] == sha1[3] && temp[4] == sha1[4]) {
						f = true;
						strcpy(str, tempStr);
						break;
					}
					R(temp, tempStr, j % 100 + 1);	// 在链中遍历寻找
				}				
			}
			UnitSHA1(str, 8, temp);
		} 
	}

	if (f) {
		printf("%s\n", str);
	}
	else {
		printf("None\n");
	}

    return 0;
}