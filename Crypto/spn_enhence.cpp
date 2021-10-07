#include<stdio.h>
#include<string.h>
#include<algorithm>

#define KEYBYTES (16) // 密钥长度
#define INPUTBYTES (1<<24) // 2^27bits
#define SPNBYTES (8)

#define ull unsigned long long 

ull s[16] = {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7};

//代换, 64
inline ull substi(ull plaintext) {
  return s[plaintext & 0xf] |
			((s[(plaintext & 0xf0) >> 4]) << 4) |
			((s[(plaintext & 0xf00) >> 8]) << 8) |
			((s[(plaintext & 0xf000) >> 12]) << 12) |
			((s[(plaintext & 0xf0000) >> 16]) << 16) |
			((s[(plaintext & 0xf00000) >> 20]) << 20) |
			((s[(plaintext & 0xf000000) >> 24]) << 24) |
			((s[(plaintext & 0xf0000000) >> 28]) << 28) |
			((s[(plaintext & 0xf00000000) >> 32]) << 32) |
			((s[(plaintext & 0xf000000000) >> 36]) << 36) |
			((s[(plaintext & 0xf0000000000) >> 40]) << 40) |
			((s[(plaintext & 0xf00000000000) >> 44]) << 44) |
			((s[(plaintext & 0xf000000000000) >> 48]) << 48) |
			((s[(plaintext & 0xf0000000000000) >> 52]) << 52) |
			((s[(plaintext & 0xf00000000000000) >> 56]) << 56) |
			((s[(plaintext & 0xf000000000000000) >> 60]) << 60);
}


ull pArr[64];
int p64[64] = {14, 45, 51, 27, 17, 42, 61, 60, 37, 53, 57, 34, 52, 58, 32, 7, 3, 44, 47, 31, 28, 21, 48, 25, 22, 4, 24, 38, 49, 12, 26, 15, 39, 0, 5, 56, 8, 11, 55, 1, 10, 16, 29, 2, 54, 40, 19, 20, 50, 41, 43, 18, 36, 62, 13, 59, 6, 46, 23, 35, 63, 9, 33, 30};
inline ull permutation(ull plaintext) {
	ull mask = 1;
	for (int i = 0; i < 64; i++) {
		pArr[i] = ((plaintext & mask) == 0? 0 : 1);
		mask <<= 1;
	}
	plaintext = 0;
	for (int i = 0; i < 64; i++) {
		plaintext ^= (pArr[p64[i]]<<i);
	}
	return plaintext;
}

inline ull SPN(ull k[5], ull plaintext){
    for(int i = 0;  i < 3; i++){
        plaintext ^= k[i];
        plaintext = permutation(substi(plaintext));  
    }
    plaintext ^= k[3];
    plaintext = substi(plaintext);
    plaintext ^=  k[4];
    return plaintext;
}

int main(){
    // 密钥， 明文， 密文， 初始向量
	ull k[5] = { 0 }, plaintext[1] = { 0 }, ciphertext[1] = {0};
	// 用于定义Z0
	ull Zi = 12345678123456789;
	// 分别读取64位，再从中得到5个轮密钥
	fread(k, SPNBYTES, 1, stdin);
	fread(k + 4, SPNBYTES, 1, stdin);
	k[1] = ((k[0] << 16) & 0xffffffffffff0000) ^ ((k[4] >> 48) & 0xffff);
	k[2] = ((k[0] << 32) & 0xffffffff00000000) ^ ((k[4] >> 32) & 0xffffffff);
	k[3] = ((k[0] << 48) & 0xffff000000000000) ^ ((k[4] >> 16) & 0xffffffffffffff);

	fread(plaintext, SPNBYTES, 1, stdin);
	// Z_i = SPN(Z_i-1)
	Zi = SPN(k, Zi);
	ciphertext[0] = plaintext[0] ^ Zi;
	fwrite(ciphertext, SPNBYTES, 1, stdout);

	// OFB模式
	for (int i = 1; i < (INPUTBYTES / SPNBYTES); i++) {
		fread(plaintext, SPNBYTES, 1, stdin);
		// yi = xi ^ z_i
		ciphertext[0] = plaintext[0] ^ Zi;
		fwrite(ciphertext, SPNBYTES, 1, stdout);
		Zi = SPN(k, Zi);
	}
	return 0;
}