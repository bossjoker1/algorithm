#include<stdio.h>
#include<gmp.h>
#include <time.h>
#include<iostream>
#pragma GCC optimize("O3") // 加快编译
using namespace std;

void calInverse(mpz_t eInverse, mpz_t E, mpz_t N) {
    mpz_t st[5000];
    int count = -1;
    for (int i = 0; i < 5000; i++) {
        mpz_init(st[i]);
    }
    mpz_t n, temp, temp1, temp2, e;
    mpz_init_set(e, E);
    mpz_init_set(n, N);
    mpz_init(temp);
    mpz_init(temp1);
    mpz_init(temp2);
    mpz_init_set_ui(temp, 0);
    mpz_sub(n, temp, n);
    // 求解e的逆
    mpz_mod(temp, e, n);
    mpz_sub(temp1, e, temp);
    mpz_div(temp1, temp1, n);
    mpz_init_set(st[0], temp1);
    while (mpz_cmp_ui(temp, 0) != 0) {
        count++;
        mpz_init_set(st[count], temp1);
        mpz_init_set(e, n);
        mpz_init_set(n, temp);
        mpz_mod(temp, e, n);
        mpz_sub(temp1, e, temp);
        mpz_div(temp1, temp1, n);
    }
    mpz_init_set_ui(temp1, 0);
    mpz_init_set_ui(temp2, 1);
    mpz_sub(n, temp1, n);
    for (int i = count; i >= 0; i--) {
        mpz_init_set(temp, temp2);
        mpz_mul(temp2, temp2, st[i]);
        mpz_sub(temp2, temp1, temp2);
        mpz_init_set(temp1, temp);
    }
    gmp_printf("%Zd\n", temp1);
	mpz_set(eInverse, temp1);
}

// 求逆
void Invert(mpz_t d, mpz_t e, mpz_t phi){
    mpz_t st[5000];
    // 保存辗转相乘的步数
    int count = -1;
    // 初始化数组，保存辗转相乘的中间结果
    for(int i = 0; i < 5000; i++){
            mpz_init(st[i]);
    }
    mpz_t temp, temp1;
    mpz_init(temp);
    mpz_init(d);
    mpz_init(temp1);

    // 求解d
    mpz_mod(temp, e, phi);
    mpz_sub(d, e, temp);
    mpz_div(d, d, phi);
    mpz_init_set(st[0], d);
    while(mpz_cmp_ui(temp, 0) != 0){
        count++;
        mpz_init_set(st[count], d);
        mpz_init_set(e, phi);
        mpz_init_set(phi, temp);
        mpz_mod(temp, e, phi);
        mpz_sub(d, e, temp);
        mpz_div(d, d, phi);
    }
    mpz_init_set_ui(d, 0);
    mpz_init_set_ui(temp1, 1);
    mpz_sub(phi, d, phi);
    for(int i = count; i >= 0; i--){
            mpz_init_set(temp, temp1);
            mpz_mul(temp1, temp1, st[i]);
            mpz_sub(temp1, d, temp1);
            mpz_init_set(d, temp);
    }
     gmp_printf("%Zd\n",d);
}

void expmod(mpz_t post, mpz_t a, mpz_t E, mpz_t N) {
	mpz_t e, n,A,temp;
	mpz_init_set(e, E);
	mpz_init_set(n, N);
	mpz_init_set(A, a);
    mpz_init_set(post, a);
	mpz_init(temp);
	mpz_set_ui(post, 1);
	mpz_mod_ui(temp, e, 2);	
	while (mpz_cmp_ui(e, 0) != 0) {	
		if (mpz_cmp_ui(temp, 1) == 0) {	
			mpz_mul(post, post, A);
			mpz_mod(post, post, n);
		}
		mpz_mul(A, A, A);
		mpz_mod(A, A, n);
		mpz_div_ui(e, e, 2);
		mpz_mod_ui(temp, e, 2);	
	}
    // gmp_printf("%Zd\n", post);
}

void CRT(mpz_t c,mpz_t d,mpz_t p,mpz_t q){
    mpz_t a;
    mpz_init(a);
    mpz_t b;
    mpz_init(b);
    expmod(a,c,d,p);
    expmod(b,c,d,q);
    mpz_t qInverse;
    mpz_init(qInverse);
    mpz_t pInverse;
    mpz_init(pInverse);
    calInverse(pInverse,p,q);
    calInverse(qInverse,q,p);
    mpz_mul(a,a,q);
    mpz_mul(a,a,qInverse);
    mpz_mul(b,b,p);
    mpz_mul(b,b,pInverse);
    mpz_add(a,a,b);
    mpz_t s;
    mpz_init(s);
    mpz_mul(s,p,q);
    mpz_mod(a,a,s);
    gmp_printf("%Zd\n",a);
}

int main(){

    int n;
    mpz_t e, p, q;
    mpz_inits(e, p, q, NULL);
    scanf("%d", &n);
    gmp_scanf("%Zd%Zd%Zd",p,q,e);

    mpz_t d;
    mpz_init(d);
    mpz_t phi;
    mpz_init(phi);
    mpz_t p2;
    mpz_t q2;
    mpz_init(p2);
    mpz_init(q2);
    mpz_sub_ui(p2, p, 1);
    mpz_sub_ui(q2, q, 1);
    mpz_mul(phi, p2, q2);

    calInverse(d, e, phi);

    for(int i = 0;i < n;i++){
        mpz_t c;
        mpz_init(c);
        gmp_scanf("%Zd",c);
        CRT(c,d,p,q);
    }

    system("pause");
    return 0;
}