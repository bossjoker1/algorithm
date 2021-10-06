#include<stdio.h>

const unsigned short s[16] = {0xe, 0x4, 0xd, 0x1, 0x2, 0xf, 0xb, 0x8, 0x3, 0xa, 0x6, 0xc, 0x5, 0x9, 0x0, 0x7}; 
const unsigned short rs[16] = {0xe, 0x3, 0x4, 0x8, 0x1, 0xc, 0xa, 0xf, 0x7, 0xd, 0x9, 0x6, 0xb, 0x2, 0x0, 0x5};
const unsigned short pos[17] = {0x0,
								0x8000, 0x4000, 0x2000, 0x1000,
                                0x0800, 0x0400, 0x0200, 0x0100,
                                0x0080, 0x0040, 0x0020, 0x0010,
                                0x0008, 0x0004, 0x0002, 0x0001};
const unsigned short pBox[17] = {0x0,
								 0x8000, 0x0800, 0x0080, 0x0008,
								 0x4000, 0x0400, 0x0040, 0x0004,
								 0x2000, 0x0200, 0x0020, 0x0002,
								 0x1000, 0x0100, 0x0010, 0x0001};
unsigned short sBox_16[65536], spBox[65536];

inline void get_spBox(){  //获得spBox 
	for(int i = 0; i < 65536; ++i){
		sBox_16[i] = (s[i >> 12] << 12) | (s[(i >> 8) & 0xf] << 8) | (s[(i >> 4) & 0xf] << 4) | s[i & 0xf];
		spBox[i] = 0;
		for(int j = 1; j <= 16; ++j){
			if(sBox_16[i] & pos[j]) spBox[i] |= pBox[j];
		}
	} 
}

int main(){
    FILE *f = fopen("../1.txt", "w+");
    get_spBox();
    fprintf(f, "{");
    for(int i = 0 ;i < 65536; i++){
        fprintf(f, "%d,", spBox[i]);
    }
    fprintf(f, "}");
    fclose(f);

    f = fopen("../2.txt", "w+");
    get_spBox();
    fprintf(f, "{");
    for(int i = 0 ;i < 65536; i++){
        fprintf(f, "%d,", sBox_16[i]);
    }
    fprintf(f, "}");
    fclose(f);
}