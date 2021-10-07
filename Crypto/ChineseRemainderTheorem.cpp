// 直接调库
#include <gmp.h>
#include <stdio.h>
// $g++ test.cpp -o test -lgmp
// #pragma GCC optimize("O3")

void CRT(mpz_t c,mpz_t d,mpz_t p,mpz_t q){
    mpz_t a;
    mpz_init(a);
    mpz_t b;
    mpz_init(b);
    mpz_powm(a,c,d,p);
    mpz_powm(b,c,d,q);
    mpz_t qInverse;
    mpz_init(qInverse);
    mpz_t pInverse;
    mpz_init(pInverse);
    mpz_invert(pInverse,p,q);
    mpz_invert(qInverse,q,p);
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


int main() {
    int n;
    mpz_t e, p, q;
    mpz_inits(e, p, q, NULL);
    scanf("%d", &n);
    gmp_scanf("%Zd%Zd%Zd",&p,&q,&e);



    mpz_t d;
    mpz_init(d);
    mpz_t phi;
    mpz_init(phi);
    mpz_t pminus1;
    mpz_t qminus1;
    mpz_init(pminus1);
    mpz_init(qminus1);
    mpz_sub_ui(pminus1, p, 1);
    mpz_sub_ui(qminus1, q, 1);
    mpz_mul(phi, pminus1, qminus1);
    // 求d
    mpz_invert(d,e,phi);

    gmp_printf("%Zd\n",d);

    for(int i = 0;i < n;i++){
        mpz_t c;
        mpz_init(c);
        gmp_scanf("%Zd",&c);
        CRT(c,d,p,q);
    }
    return 0;
}
