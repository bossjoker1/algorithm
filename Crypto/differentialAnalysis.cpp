#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iterator>
#pragma GCC optimize("O3") // 加快编译
//#include<iostream>
using namespace std;

#define getc() (_b1==_b2?fread(_b,1,100000,stdin),_b2=_b+100000,*((_b1=_b)++):*(_b1++))
char _b[100000], * _b1, * _b2;

// 0为加密，1为解密
short int sbox[2][16] = { { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7 },
	{14, 3, 4, 8, 1, 12, 10, 15, 7, 13, 9, 6, 11, 2, 0, 5} };

unsigned short subs(int mode, unsigned short text) {

	return  (sbox[mode][(text & 0xF000) >> 12] << 12) +
		(sbox[mode][(text & 0x0F00) >> 8] << 8) +
		(sbox[mode][(text & 0x00F0) >> 4] << 4) +
		(sbox[mode][(text & 0x000F)]);

};

unsigned short p(int mode, unsigned short x) {
	return (x & 0x0001) | ((x & 0x0010) >> 3) | ((x & 0x0100) >> 6) |
		((x & 0x1000) >> 9) | ((x & 0x0002) << 3) | (x & 0x0020) |
		((x & 0x0200) >> 3) | ((x & 0x2000) >> 6) | ((x & 0x0004) << 6) |
		((x & 0x0040) << 3) | (x & 0x0400) | ((x & 0x4000) >> 3) |
		((x & 0x0008) << 9) | ((x & 0x0080) << 6) | ((x & 0x0800) << 3) |
		(x & 0x8000);
}

unsigned int SPN(unsigned int key, unsigned short plaintext, unsigned short ciphertext, int mode) {
	unsigned short roundKey[5];
	roundKey[0] = ((key & 0xFFFF0000) >> 16);
	roundKey[1] = ((key & 0x0FFFF000) >> 12);
	roundKey[2] = ((key & 0x00FFFF00) >> 8);
	roundKey[3] = ((key & 0x000FFFF0) >> 4);
	roundKey[4] = (key & 0x0000FFFF);

	unsigned short text = plaintext;

	for (int i = 0; i <= 2; ++i) {
		text ^= roundKey[i];
		text = subs(mode, text);
		text = p(mode, text);
	}
	text ^= roundKey[3];
	text = subs(mode, text);
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
	int n, maxNum[2];
	pair<int, int> cnt1[256], cnt2[256];
	unsigned int plain[65536], cipher[65536], temp1[4], temp2[4], k[8], lastKey2, key, count;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		lastKey2 = -1;
		fill(cnt1, cnt1 + 256, pair<int, int>(0, 0));
		fill(cnt2, cnt2 + 256, pair<int, int>(0, 0));
		for (int j = 0; j < 65536; j++) {
			cipher[j] = read();
		}
		// 计算第一条链
		for (int j = 0; j < 65536; j += 37) {
			if (((cipher[j] ^ cipher[j ^ 0xb00]) & 0xf0f0) == 0) {
				for (k[5] = 0; k[5] < 16; k[5]++) {
					for (k[7] = 0; k[7] < 16; k[7]++) {
						temp1[1] = ((cipher[j] & 0xf00) >> 8) ^ k[5];
						temp1[3] = ((cipher[j] & 0xf) ^ k[7]);
						temp1[1] = sbox[1][temp1[1]];
						temp1[3] = sbox[1][temp1[3]];
						temp2[1] = ((cipher[j ^ 0xb00] & 0xf00) >> 8) ^ k[5];
						temp2[3] = ((cipher[j ^ 0xb00] & 0xf) ^ k[7]);
						temp2[1] = sbox[1][temp2[1]];
						temp2[3] = sbox[1][temp2[3]];

						temp1[1] ^= temp2[1];
						temp1[3] ^= temp2[3];
						if (temp1[1] == 6 && temp1[3] == 6)
							cnt1[k[5] * 16 + k[7]].first++;
					}
				}
			}
			if (((cipher[j] ^ cipher[j ^ 0x50]) & 0x0f0f) == 0) {
				for (k[4] = 0; k[4] < 16; k[4]++) {
					for (k[6] = 0; k[6] < 16; k[6]++) {
						temp1[0] = ((cipher[j] & 0xf000) >> 12) ^ k[4];
						temp1[2] = ((cipher[j] & 0xf0) >> 4) ^ k[6];
						temp1[0] = sbox[1][temp1[0]];
						temp1[2] = sbox[1][temp1[2]];
						temp2[0] = ((cipher[j ^ 0x50] & 0xf000) >> 12) ^ k[4];
						temp2[2] = ((cipher[j ^ 0x50] & 0xf0) >> 4) ^ k[6];
						temp2[0] = sbox[1][temp2[0]];
						temp2[2] = sbox[1][temp2[2]];

						temp1[0] ^= temp2[0];
						temp1[2] ^= temp2[2];
						if (temp1[0] == 5 && temp1[2] == 5)
							cnt2[k[4] * 16 + k[6]].first++;
					}
				}
			}
		}
		// 得到部分密钥
		for (int j = 0; j < 256; j++) {
			cnt1[j].second = j;
			cnt2[j].second = j;
		}
		sort(cnt1, cnt1 + 256);

		sort(cnt2, cnt2 + 256);
		k[4] = cnt2[255].second / 16;
		k[6] = cnt2[255].second % 16;
		for (int j = 255; j >= 0; j--) {
			k[5] = cnt1[j].second / 16;
			k[7] = cnt1[j].second % 16;

			for (k[0] = 0; k[0] < 65536; k[0]++) {
				key = (k[0] << 16) | (k[4] << 12) | (k[5] << 8) | (k[6] << 4) | k[7];
				for (count = 0; count < 10; count++) {
					if (!SPN(key, count * 1000 + 30000, cipher[count * 1000 + 30000], 0))
						break;
				}
				if (count == 10) {
					output(key);
					break;
				}
			}
			if (count == 10)
				break;
		}
	}
	return 0;
}