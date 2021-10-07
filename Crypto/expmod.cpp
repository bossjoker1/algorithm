#include<stdio.h>
#include<gmpxx.h>
#include<time.h>
#pragma GCC optimize("O2") // 加快编译

inline int read(){
    int x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}

mpz_class mymod(mpz_class m, mpz_class e, mpz_class N) {
	mpz_class  a, temp;
	a = 1;
	temp = e % 2;	
	while (e != 0) {	
		if (temp == 1) {	
			a = a * m;
			a = a % N;
		}
		m = m * m;
		m = m % N;
		e = e / 2;
		temp = e % 2;	
	}
    return a;
}

int main(){
    int n;
    mpz_class e,m,p,q,N;
    n = read();

    for(int i =  0; i < n; i++){
        gmp_scanf("%Zd%Zd%Zd%Zd", &e, &m,&p, &q);
        N = p * q;
        m = mymod(m, e, N);
		gmp_printf("%Zd\n", m);
    }
	system("pause");
    return 0;
}