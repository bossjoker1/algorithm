#include<stdio.h>
#include<string.h>
#include<algorithm>

#define KEYBYTES (16) // 密钥长度
#define INPUTBYTES (1<<24) // 2^27bits
#define SPNBYTES (8)

#define ull unsigned long long 

ull substitution[16] = {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7};

//代换, 64位
inline ull substi(ull plaintext) {
  return substitution[plaintext & 0xf] |
			((substitution[(plaintext & 0xf0) >> 4]) << 4) |
			((substitution[(plaintext & 0xf00) >> 8]) << 8) |
			((substitution[(plaintext & 0xf000) >> 12]) << 12) |
			((substitution[(plaintext & 0xf0000) >> 16]) << 16) |
			((substitution[(plaintext & 0xf00000) >> 20]) << 20) |
			((substitution[(plaintext & 0xf000000) >> 24]) << 24) |
			((substitution[(plaintext & 0xf0000000) >> 28]) << 28) |
			((substitution[(plaintext & 0xf00000000) >> 32]) << 32) |
			((substitution[(plaintext & 0xf000000000) >> 36]) << 36) |
			((substitution[(plaintext & 0xf0000000000) >> 40]) << 40) |
			((substitution[(plaintext & 0xf00000000000) >> 44]) << 44) |
			((substitution[(plaintext & 0xf000000000000) >> 48]) << 48) |
			((substitution[(plaintext & 0xf0000000000000) >> 52]) << 52) |
			((substitution[(plaintext & 0xf00000000000000) >> 56]) << 56) |
			((substitution[(plaintext & 0xf000000000000000) >> 60]) << 60);
}


unsigned long long permutationArr[64];
int permutationPos[64] = {0,16,32,48,1,17,33,49,2,18,34,50,3,19,35,51,4,20,36,52,5,21,37,53,6,22,38,54,7,23,39,55,8,24,40,56,9,25,41,57,10,26,42,58,11,27,43,59,12,28,44,60,13,29,45,61,14,30,46,62,15,31,47,63};
unsigned long long permutation(unsigned long long plaintext) {
	unsigned long long mask = 1;
	for (int i = 0; i < 64; i++) {
		permutationArr[i] = ((plaintext & mask) == 0? 0 : 1);
		mask <<= 1;
	}
	plaintext = 0;
	for (int i = 0; i < 64; i++) {
		plaintext ^= (permutationArr[permutationPos[i]]<<i);
	}
	return plaintext;
}

// //置换
// inline ull replace(ull x) {
//     // 64位p盒位运算
//   return (x & 0x0000000000000001) | ((x & 0x0000000000000010) >> 3) | ((x & 0x0000000000000100) >> 6) |((x & 0x0000000000001000) >> 9) |
//          ((x & 0x000000000000002) << 3) | (x & 0x0000000000000020) |((x & 0x0000000000000200) >> 3) | ((x & 0x0000000000002000) >> 6) |
//          ((x & 0x0000000000000004) << 6) |((x & 0x0000000000000040) << 3) | (x & 0x0000000000000400) | ((x & 0x0000000000004000) >> 3) |
//          ((x & 0x0000000000000008) << 9) | ((x & 0x0000000000000080) << 6) | ((x & 0x0000000000000800) << 3) |(x & 0x0000000000008000)|
//          (x & 0x0000000000010000) | ((x & 0x0000000000100000) >> 3) | ((x & 0x0000000001000000) >> 6) |((x & 0x0000000010000000) >> 9) |
//          ((x & 0x000000000020000) << 3) | (x & 0x0000000000200000) |((x & 0x0000000002000000) >> 3) | ((x & 0x0000000020000000) >> 6) |
//          ((x & 0x0000000000040000) << 6) |((x & 0x0000000000400000) << 3) | (x & 0x0000000004000000) | ((x & 0x0000000040000000) >> 3) |
//          ((x & 0x0000000000080000) << 9) | ((x & 0x0000000000800000) << 6) | ((x & 0x0000000008000000) << 3) |(x & 0x000000080000000)|
//          (x & 0x0000000100000000) | ((x & 0x0000001000000000) >> 3) | ((x & 0x0000010000000000) >> 6) |((x & 0x0000100000000000) >> 9) |
//          ((x & 0x000000200000000) << 3) | (x & 0x0000002000000000) |((x & 0x0000020000000000) >> 3) | ((x & 0x0000200000000000) >> 6) |
//          ((x & 0x0000000400000000) << 6) |((x & 0x0000004000000000) << 3) | (x & 0x0000004000000000) | ((x & 0x0000400000000000) >> 3) |
//          ((x & 0x0000000800000000) << 9) | ((x & 0x0000008000000000) << 6) | ((x & 0x0000080000000000) << 3) |(x & 0x0000800000000000)|
//          (x & 0x0001000000000000) | ((x & 0x0010000000000000) >> 3) | ((x & 0x0100000000000000) >> 6) |((x & 0x1000000000000000) >> 9) |
//          ((x & 0x000200000000000) << 3) | (x & 0x0020000000000000) |((x & 0x0200000000000000) >> 3) | ((x & 0x2000000000000000) >> 6) |
//          ((x & 0x0004000000000000) << 6) |((x & 0x0040000000000000) << 3) | (x & 0x0000000000000000) | ((x & 0x4000000000000000) >> 3) |
//          ((x & 0x0008000000000000) << 9) | ((x & 0x0080000000000000) << 6) | ((x & 0x0800000000000000) << 3) |(x & 0x8000000000000000);
// }

ull SPN(ull k[5], ull plaintext){
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
	unsigned long long k[5] = { 0 }, plaintext[1] = { 0 }, ciphertext[1] = {0}, initialValue = 92435678;
	fread(k, SPNBYTES, 1, stdin);
	fread(k + 4, SPNBYTES, 1, stdin);
	k[1] = ((k[0] << 16) & 0xffffffffffff0000) ^ ((k[4] >> 48) & 0xffff);
	k[2] = ((k[0] << 32) & 0xffffffff00000000) ^ ((k[4] >> 32) & 0xffffffff);
	k[3] = ((k[0] << 48) & 0xffff000000000000) ^ ((k[4] >> 16) & 0xffffffffffffff);

	fread(plaintext, SPNBYTES, 1, stdin);
	ciphertext[0] = (plaintext[0] ^ SPN(k, initialValue));
	fwrite(ciphertext, SPNBYTES, 1, stdout);

	// CFB模式
	for (int i = 1; i < (INPUTBYTES / SPNBYTES); i++) {
		fread(plaintext, SPNBYTES, 1, stdin);
		ciphertext[0] = (plaintext[0] ^ SPN(k, ciphertext[0]));
		fwrite(ciphertext, SPNBYTES, 1, stdout);
	}
	return 0;
}