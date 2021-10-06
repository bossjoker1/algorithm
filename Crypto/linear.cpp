#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iterator>
#pragma GCC optimize("O3") // 加快编译
using namespace std;

#define getc() (_b1==_b2?fread(_b,1,100000,stdin),_b2=_b+100000,*((_b1=_b)++):*(_b1++))
char _b[100000], * _b1, * _b2;

// 0为加密，1为解密
short int S[2][16] = { { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7 },
	{14, 3, 4, 8, 1, 12, 10, 15, 7, 13, 9, 6, 11, 2, 0, 5} };

unsigned short sub(int c, unsigned short text) {

	return  (S[c][(text & 0xF000) >> 12] << 12) +
		(S[c][(text & 0x0F00) >> 8] << 8) +
		(S[c][(text & 0x00F0) >> 4] << 4) +
		(S[c][(text & 0x000F)]);

};

unsigned short p(int c, unsigned short x) {
	return (x & 0x0001) | ((x & 0x0010) >> 3) | ((x & 0x0100) >> 6) |
		((x & 0x1000) >> 9) | ((x & 0x0002) << 3) | (x & 0x0020) |
		((x & 0x0200) >> 3) | ((x & 0x2000) >> 6) | ((x & 0x0004) << 6) |
		((x & 0x0040) << 3) | (x & 0x0400) | ((x & 0x4000) >> 3) |
		((x & 0x0008) << 9) | ((x & 0x0080) << 6) | ((x & 0x0800) << 3) |
		(x & 0x8000);
}

unsigned int SPN(unsigned int key, unsigned short plaintext, unsigned short ciphertext, int c) {
	unsigned short roundKey[5];
	roundKey[0] = ((key & 0xFFFF0000) >> 16);
	roundKey[1] = ((key & 0x0FFFF000) >> 12);
	roundKey[2] = ((key & 0x00FFFF00) >> 8);
	roundKey[3] = ((key & 0x000FFFF0) >> 4);
	roundKey[4] = (key & 0x0000FFFF);

	unsigned short text = plaintext;

	for (int i = 0; i <= 2; ++i) {
		text ^= roundKey[i];
		text = sub(c, text);
		text = p(c, text);
	}
	text ^= roundKey[3];
	text = sub(c, text);
	text ^= roundKey[4];

	return (text == ciphertext);
}

// 快读
inline unsigned short read()
{
	unsigned short x = 0;
	char c = getc();//x代表返回值，c代表读取的字符
	while (c != ' ' && c != '\n') {
		x = x * 16 + ((c >= 'a') ? (c - 'a' + 10) : (c - '0'));
		c = getc();
	}
	return x;
}

inline void output(register unsigned int key){
	char buf[8];  //输出缓冲区
	for(int i = 0; i < 8; ++i){
		buf[7 - i] = key & 0xf;
		if(buf[7 - i] < 10) buf[7 - i] += '0';
		else buf[7 - i] = (buf[7 - i] - 10) + 'a'; 
		key >>= 4;
	}
	for(int i = 0; i < 8; ++i) putchar(buf[i]);
	putchar('\n');
}

int main()
{
	int n, count, maxNum[2];
	pair<int, int> cnt1[256], cnt2[256];
	unsigned plain[8000], cipher[8000], temp[4], k[8], lastKey2, key;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		lastKey2 = -1;
		fill(cnt1, cnt1 + 256, pair<int, int>(-4000, 0));
		for (int j = 0; j < 8000; j++) {
			plain[j] = read();
			cipher[j] = read();
		}
		// 计算第一条链
		for (int j = 0; j < 8000; j++) {
			for (k[5] = 0; k[5] < 16; k[5]++) {
				for (k[7] = 0; k[7] < 16; k[7]++) {
					temp[1] = S[1][((cipher[j] & 0xf00) >> 8) ^ k[5]];
					temp[3] = S[1][((cipher[j] & 0xf) ^ k[7])];
					if ((((plain[j] & 0x800) >> 11) ^ ((plain[j] & 0x200) >> 9) ^ ((plain[j] & 0x100) >> 8) ^
						(temp[1] & 0x1) ^ ((temp[1] & 0x4) >> 2) ^ (temp[3] & 0x1) ^ ((temp[3] & 0x4) >> 2)) == 0)
						cnt1[k[5] * 16 + k[7]].first++;
				}
			}
		}
		// 得到部分密钥
		for (int j = 0; j < 256; j++) {
			cnt1[j].second = j;
			cnt1[j].first = abs(cnt1[j].first);
		}
		sort(cnt1, cnt1 + 256);

		for (int j = 255; j >= 0; j--) {
			lastKey2 = k[5];
			// 取出密钥
			k[5] = cnt1[j].second / 16;
			k[7] = cnt1[j].second % 16;

			// 计算第二条链
			if (j == 255 || lastKey2 != k[5]) {
				fill(cnt2, cnt2 + 256, pair<int, int>(-4000, 0));
				for (int j = 0; j < 8000; j++) {
					for (k[4] = 0; k[4] < 16; k[4]++) {
						for (k[6] = 0; k[6] < 16; k[6]++) {
							temp[0] = S[1][((cipher[j] & 0xf000) >> 12) ^ k[4]];
							temp[1] = S[1][((cipher[j] & 0xf00) >> 8) ^ k[5]];
							temp[2] = S[1][((cipher[j] & 0xf0) >> 4) ^ k[6]];
							if ((((plain[j] & 0x800) >> 11) ^ ((plain[j] & 0x400) >> 10) ^
								((temp[0] & 0x4) >> 2) ^ (temp[0] & 0x1) ^ ((temp[1] & 0x4) >> 2) ^ (temp[1] & 0x1) ^ ((temp[2] & 0x4) >> 2) ^ (temp[2] & 0x1)) == 0)
								cnt2[k[4] * 16 + k[6]].first++;
						}
					}
				}
				for (int j = 0; j < 256; j++) {
					cnt2[j].second = j;
					cnt2[j].first = abs(cnt2[j].first);
				}
				maxNum[0] = max_element(cnt2, cnt2 + 256) - cnt2;
				cnt2[maxNum[0]].first = 0;
				maxNum[1] = (*max_element(cnt2, cnt2 + 256)).second;
			}


			k[4] = maxNum[0] / 16;
			k[6] = maxNum[0] % 16;
			for (k[0] = 0; k[0] < 65535; k[0]++) {
				key = (k[0] << 16) | (k[4] << 12) | (k[5] << 8) | (k[6] << 4) | k[7];
				for (count = 0; count < 2; count++) {
					if (!SPN(key, plain[count], cipher[count], 0))
						break;
				}
				if (count == 2) {
					output(key);
					break;
				}
			}
			if (count == 2)
				break;
		}
	}
	return 0;
}