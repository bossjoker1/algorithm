#include<stdio.h>
#include<gmp.h>
#include <time.h>
#include<iostream>
using namespace std;

bool Prime(mpz_t p){
    if (mpz_probab_prime_p(p, 49) != 0){
        return true;
    }else{
        return false;
    }
}

int main(){
    int n;
    mpz_t e,p,q;
    mpz_init(e);
    mpz_init(p);
    mpz_init(q);
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        gmp_scanf("%Zd%Zd%Zd", &e, &p, &q);
        mpz_t phi, gcd, d, temp, temp1;
        mpz_init(phi);
        mpz_init(gcd);
        mpz_init(d);
        mpz_init(temp);
        mpz_init(temp1);

        mpz_sub(temp, p, q);
        mpz_abs(temp, temp);
        mpz_div_ui(temp1, p, 10);
        if(mpz_cmp_ui(e, 10) < 0){
            printf("ERROR\n");
            continue;
        }

        if(mpz_cmp(temp, temp1) < 0){
            printf("ERROR\n");
            continue;
        }

        if(!Prime(p)||!Prime(q)){
            printf("ERROR\n");
            continue;
        }

        mpz_sub_ui(p, p, 1); // p-1 => p
        mpz_sub_ui(q, q, 1); // q-1 => q

        mpz_gcd(gcd, p, q);
        if(mpz_cmp_ui(gcd, 100000) > 0){
            printf("ERROR\n");
            continue;
        }

        mpz_mul(phi, p, q); // phi = (p-1)*(q-1)
        mpz_gcd(gcd, e, phi);
        //gmp_printf("gcd: %Zd \n", gcd);
        if(mpz_cmp_ui(gcd, 1) != 0){
            printf("ERROR\n");
        }else{
            mpz_invert(d, e, phi);
            gmp_printf("%Zd\n", d);
        }
    }
    system("pause");
    return 0;    
}