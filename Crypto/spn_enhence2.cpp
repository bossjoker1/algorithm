// SPN CBC模式
// SPN分组长度32位 密钥长度128位
// 重写了P盒
// Nr = 13（跑四轮）
#include<stdio.h>
#include<string.h>
#include<map>
#include<algorithm>
#include<iterator>
#define KEYBYTES (16)
#define SPNBYTES (8)
#define INPUTBYTES (1<<24)

using namespace std;

typedef unsigned int ui; 

ui substitution[2][16] = { { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7 }, {14, 3, 4, 8, 1, 12, 10, 15, 7, 13, 9, 6, 11, 2, 0, 5} };
ui pArr[32];
int permutationPos[2][64] = { {0,16,32,48,1,17,33,49,2,18,34,50,3,19,35,51,4,20,36,52,5,21,37,53,6,22,38,54,7,23,39,55,8,24,40,56,9,25,41,57,10,26,42,58,11,27,43,59,12,28,44,60,13,29,45,61,14,30,46,62,15,31,47,63},
							{0,4,8,12,16,20,24,28,32,36,40,44,48,52,56,60,1,5,9,13,17,21,25,29,33,37,41,45,49,53,57,61,2,6,10,14,18,22,26,30,34,38,42,46,50,54,58,62,3,7,11,15,19,23,27,31,35,39,43,47,51,55,59,63} };

int per32[32] = {4, 18, 22, 15, 27, 3, 16, 17, 1, 29, 10, 30, 0, 8, 9, 25, 23, 13, 7, 12, 20, 24, 14, 28, 5, 21, 6, 19, 2, 26, 31, 11};
ui permutation(ui plaintext, int mode) {
	unsigned long long mask = 1;
	for (int i = 0; i < 32; i++) {
		pArr[i] = ((plaintext & mask) == 0? 0 : 1);
		mask <<= 1;
	}
	plaintext = 0;
	for (int i = 0; i < 32; i++) {
		plaintext ^= (pArr[per32[i]]<<i);
	}
	return plaintext;
}

ui SPN(ui k[5], ui plaintext, int mode) {
	for (int i = 0; i < 3; i++) {
		if (mode == 1) {
			if (i == 0)
				plaintext ^= k[4];
			else
				plaintext ^= permutation(k[4 - i], mode);
		}
		else
			plaintext ^= k[i];
		plaintext = substitution[mode][plaintext & 0xf] |
			((substitution[mode][(plaintext & 0xf0) >> 4]) << 4) |
			((substitution[mode][(plaintext & 0xf00) >> 8]) << 8) |
			((substitution[mode][(plaintext & 0xf000) >> 12]) << 12) |
			((substitution[mode][(plaintext & 0xf0000) >> 16]) << 16) |
			((substitution[mode][(plaintext & 0xf00000) >> 20]) << 20) |
			((substitution[mode][(plaintext & 0xf000000) >> 24]) << 24) |
			((substitution[mode][(plaintext & 0xf0000000) >> 28]) << 28);
		plaintext = permutation(plaintext, mode);
	}
	if (mode == 1)
		plaintext ^= permutation(k[1], mode);
	else
		plaintext ^= k[3];
	plaintext = substitution[mode][plaintext & 0xf] |
		((substitution[mode][(plaintext & 0xf0) >> 4]) << 4) |
		((substitution[mode][(plaintext & 0xf00) >> 8]) << 8) |
		((substitution[mode][(plaintext & 0xf000) >> 12]) << 12) |
		((substitution[mode][(plaintext & 0xf0000) >> 16]) << 16) |
		((substitution[mode][(plaintext & 0xf00000) >> 20]) << 20) |
		((substitution[mode][(plaintext & 0xf000000) >> 24]) << 24) |
		((substitution[mode][(plaintext & 0xf0000000) >> 28]) << 28);
	if (mode == 1)
		plaintext ^= k[0];
	else
		plaintext ^= k[4];
	return plaintext;
}
int main()
{
	// 密钥， 明文， 密文， 初始向量
	ui k[13] = { 0 }, plaintext[1] = { 0 }, ciphertext[1] = {0}, initialValue = 22220012;
	fread(k, SPNBYTES, 1, stdin);
	fread(k + 4, SPNBYTES, 1, stdin);
	k[1] = ((k[0] << 16) & 0xffffffffffff0000) ^ ((k[4] >> 48) & 0xffff);
	k[2] = ((k[0] << 32) & 0xffffffff00000000) ^ ((k[4] >> 32) & 0xffffffff);
	k[3] = ((k[0] << 48) & 0xffff000000000000) ^ ((k[4] >> 16) & 0xffffffffffffff);

	fread(plaintext, SPNBYTES, 1, stdin);
	plaintext[0] ^= initialValue;
	ciphertext[0] = SPN(k, plaintext[0], 0);
	fwrite(ciphertext, SPNBYTES, 1, stdout);
	// CBC模式
	for (int i = 1; i < (INPUTBYTES / SPNBYTES); i++) {
		fread(plaintext, SPNBYTES, 1, stdin);
		plaintext[0] ^= ciphertext[0];
		ciphertext[0] = SPN(k, plaintext[0], 0);
		fwrite(ciphertext, SPNBYTES, 1, stdout);
	}
	return 0;
}