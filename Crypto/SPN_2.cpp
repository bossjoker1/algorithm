#include <stdio.h>
#define us unsigned int
// s盒子 0为加密，1为解密
us s[2][16] = { { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7 }, 
                {14, 3, 4, 8, 1, 12, 10, 15, 7, 13, 9, 6, 11, 2, 0, 5} };

us key[6];
// 16进制读入
inline int read() {
  int h = 0;
  char c = getchar();
  while (c != ' ' && c != '\n') {
    if (c >= '0' && c <= '9')
      h = (h << 4) + c - '0';
    else if (c >= 'a' && c <= 'f')
      h = (h << 4) + c - 'a' + 10;
    c = getchar();
  }
  return h;
}

inline void print(us x) {
  for (int i = 1; i <= 4; i++) {
    int c = (x >> (4 * (4 - i))) & 0xF;
    if (c >= 0 && c <= 9)
      putchar('0' + c);
    else if (c >= 10 && c <= 15)
      putchar('a' + c - 10);
  }
}


//代换
inline us sub(us x, int c) {
  return ((s[c][x & 0x000f]) | ((s[c][(x & 0x00f0) >> 4]) << 4) |
          ((s[c][(x & 0x0f00) >> 8]) << 8) |
          ((s[c][(x & 0xf000) >> 12]) << 12));
}

//置换
inline us p(us x) {
  return (x & 0x0001) | ((x & 0x0010) >> 3) | ((x & 0x0100) >> 6) |
         ((x & 0x1000) >> 9) | ((x & 0x0002) << 3) | (x & 0x0020) |
         ((x & 0x0200) >> 3) | ((x & 0x2000) >> 6) | ((x & 0x0004) << 6) |
         ((x & 0x0040) << 3) | (x & 0x0400) | ((x & 0x4000) >> 3) |
         ((x & 0x0008) << 9) | ((x & 0x0080) << 6) | ((x & 0x0800) << 3) |
         (x & 0x8000);
}

inline us SPN(us text, int c) {
  us w, u, v;
  w = text;
  if(c == 0){
    for (int i = 1; i <= 3; ++i) {
      u = w ^ key[i];
      v = sub(u, c);
      w = p(v);
    }
    u = w ^ key[4];
    v = sub(u, c);
    w = v ^ key[5];
  }else{
    v = w ^ key[5];
    u = sub(v, c);
    w = u ^ key[4];
    for (int i = 3; i >= 1; --i) {
      v = p(w);
      u = sub(v, c);
      w = u ^ key[i];
    }
  }
  return w;
}

int main() {
  int K, n;
  us P, C;
  scanf("%d", &n);
  getchar();
  for (int i = 1; i <= n; ++i) {
    K = read();
    P = read();
    for (int i = 5; i >= 1; i--) {
      key[i] = K & 0x0000ffff;
      K = K >> 4;
    }
    C = SPN(P, 0);
    print(C);
    putchar(' ');
    C ^= 0x0001;
    print(SPN(C, 1));
    putchar('\n');
  }
  return 0;
}