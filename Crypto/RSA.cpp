#include<stdio.h>
#include<gmp.h>
#include <time.h>
#include<iostream>
#pragma GCC optimize("O3") // 加快编译
using namespace std;

bool isPrime(mpz_t paraN){
        int count = 0;
        gmp_randstate_t state;
        gmp_randinit_mt(state);
        mpz_t b, t, temp, a, n;
        mpz_init(b);
        mpz_init(n);
        mpz_init(a);
        mpz_init(t);
        mpz_init(temp);
        mpz_init_set(n, paraN);
        mpz_init_set(n, paraN);
        mpz_set(t, n);
        mpz_sub_ui(t,t,1);
        mpz_mod_ui(b, t, 2);
        while(mpz_cmp_ui(b, 0) == 0){           //  求解t
                mpz_div_ui(t, t, 2);
                mpz_mod_ui(b, t, 2);
                count++;
        }
        mpz_sub_ui(t,n,1);
        if(count == 0){
                return false;           // 偶数直接排除
        }
        for(int i = 0; i < 300; i++){
                //mpz_init_set_ui(a, 4);
                mpz_urandomm(a, state, n);              // 随机选择a
                if(mpz_cmp_ui(a, 0) != 0 && mpz_cmp_ui(a, 1) != 0){
                        mpz_powm(temp, a, t, n);
                        if(mpz_cmp_ui(temp, 1) == 0){           //  是素数
                                return true;
                        }
                        for(int j = 0; j < count; j++){
                                if(mpz_cmp(temp, t) == 0){          // 是素数
                                        return true;
                                }
                                mpz_powm_ui(temp, temp, 2, n);
                        }
                }
        }
        //gmp_printf("%Zd\n",n);
        return false;           // 不是素数
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

        if(!isPrime(p)||!isPrime(q)){
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