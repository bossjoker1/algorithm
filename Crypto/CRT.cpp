#include <gmpxx.h>
#include <iostream>
#include <time.h>
#pragma GCC optimize("O3")
using namespace std;

#define rep(i,l,r) for(int i=(l);i<(r);++i)

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

// 错误检测需要在前面完成
mpz_class myInvert(mpz_class e, mpz_class phi){
        mpz_class st[5000];
        int count = -1;
        mpz_class temp, temp1, temp2, phi_fix;
        phi_fix = phi;
        // 求解d
        temp = e % phi;
        temp1 = (e - temp) / phi;
        st[0] = temp1;
        while(temp !=  0){
                count++;
                st[count] = temp1;
                e = phi;
                phi = temp;
                temp = e % phi;
                temp1 = (e - temp) / phi;
        }
        // 开始逆序求d
        temp1 = 0;
        temp2 = 1;
        phi = temp1 - phi;
        for(int i = count; i >= 0; i--){
                temp = temp2;
                temp2 = temp2 * st[i];
                temp2 = temp1 - temp2;
                temp1 = temp;
        }
        while(temp1 < 0){
            temp1 = temp1 + phi_fix;
        }
        return temp1;
}

void CRT(mpz_class c, mpz_class d, mpz_class p, mpz_class q){
    mpz_class a, b, sum;
    mpz_powm(a.get_mpz_t (),c.get_mpz_t (),d.get_mpz_t (),p.get_mpz_t ());
    mpz_powm(b.get_mpz_t (),c.get_mpz_t (),d.get_mpz_t (),q.get_mpz_t ());
    mpz_class rp, rq;
    rp =  myInvert(p,q);
    rq =  myInvert(q,p);
    sum = (a*q*rq + b*p*rp) % (p*q);
    gmp_printf("%Zd\n",sum);
}

int main(){
    int n;
    mpz_class e, p, q;
    n = read();
    gmp_scanf("%Zd%Zd%Zd",&p,&q,&e);    

    mpz_class d, phi;

    phi = (p-1) * (q-1);

    d = myInvert(e, phi);

    rep(i, 0, n){
        mpz_class c;
        gmp_scanf("%Zd",&c);
        CRT(c, d, p, q);
    }

    system("pause");
    return 0;
}