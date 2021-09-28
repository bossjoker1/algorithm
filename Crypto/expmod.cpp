#include<stdio.h>
#include<gmp.h>
#pragma GCC optimize("O3") // 加快编译


void expmod(mpz_t a, mpz_t E, mpz_t N) {
	mpz_t e, n,A,temp;
	mpz_init_set(e, E);
	mpz_init_set(n, N);
	mpz_init_set(A, a);
	mpz_init(temp);
	mpz_set_ui(a, 1);
	mpz_mod_ui(temp, e, 2);	
	while (mpz_cmp_ui(e, 0) != 0) {	
		if (mpz_cmp_ui(temp, 1) == 0) {	
			mpz_mul(a, a, A);
			mpz_mod(a, a, n);
		}
		mpz_mul(A, A, A);
		mpz_mod(A, A, n);
		mpz_div_ui(e, e, 2);
		mpz_mod_ui(temp, e, 2);	
	}
    gmp_printf("%Zd\n", a);
}

int main(){
    int n;
    mpz_t e,m,p,q,N;
    mpz_init(e);
    mpz_init(p);
    mpz_init(q);
    mpz_init(N);
	mpz_init(m);
    scanf("%d", &n);

    for(int i =  0; i < n; i++){
        gmp_scanf("%Zd%Zd%Zd%Zd", &e, &m,&p, &q);
        mpz_mul(N, p, q);
        expmod(m, e, N);
    }
    return 0;
}