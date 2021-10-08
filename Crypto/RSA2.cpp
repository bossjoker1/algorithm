#include <gmpxx.h>
#include <iostream>
#include <time.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<(r);++i)

inline int read(){
    int x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}

bool isPrime(mpz_class paraN){
        int count = 0;
        gmp_randstate_t state;
        gmp_randinit_mt(state);
        mpz_class b, t, temp, a, n;
        n = paraN;
        t = n;
        t = t - 1;
        b = t % 2;
        while(b == 0){           //  求解t
                t = t / 2;
                b = t % 2;
                count++;
        }
        t = n - 1;
        if(count == 0){
                return false;           // 偶数直接排除
        }
        for(int i = 0; i < 300; i++){
                mpz_urandomm(a.get_mpz_t(), state, n.get_mpz_t());              // 随机选择a
                if(a != 0  && a != 1){
                        mpz_powm(temp.get_mpz_t(), a.get_mpz_t(), t.get_mpz_t(), n.get_mpz_t());
                        if(temp == 1){           //  是素数
                                return true;
                        }
                        for(int j = 0; j < count; j++){
                                if(temp == t){          // 是素数
                                        return true;
                                }
                                mpz_powm_ui(temp.get_mpz_t(), temp.get_mpz_t(), 2, n.get_mpz_t());
                        }
                }
        }
        return false;

}

mpz_class mygcd(mpz_class paraA, mpz_class paraB){
    mpz_class temp, a, b;
    a = paraA;
    b = paraB;
    temp  = a % b;
    // 辗转相除法
    while(temp != 0){
            a = b;
            b = temp;
            temp = a % b;
    }
    return b;   
}


// 错误检测需要在前面完成
mpz_class myInvert(mpz_class e, mpz_class phi){
        mpz_class q[5000];
        int count = -1;
        mpz_class temp, temp1, temp2;

        // 求解d
        temp = e % phi;
        temp1 = (e - temp) / phi;
        q[0] = temp1;
        while(temp !=  0){
                count++;
                q[count] = temp1;
                e = phi;
                phi = temp;
                temp = e % phi;
                temp1 = (e - temp) / phi;
        }
        // 开始逆序求d
        temp1 = 0;
        temp2 = 1;
        for(int i = count; i >= 0; i--){
                temp = temp2;
                temp2 = temp1 - temp2 * q[i];
                temp1 = temp;
        }
        return temp1;
}

int main(){
    int n;
    n = read();
    mpz_class e, p, q;

    rep(i, 0, n){
        gmp_scanf("%Zd%Zd%Zd", &e, &p, &q);

        if(e <= 9){              // e过小
            printf("ERROR\n");
            continue;
        }

        mpz_class t1, t2, phi, gcd, d;

        t1 = abs(p - q);
        t2 = p / 10;

        if(t1 < t2){
            printf("ERROR\n");
            continue;
        }

        if(!isPrime(p)||!isPrime(q)){
            printf("ERROR\n");
            continue;
        }

        p = p - 1;
        q = q - 1;

        gcd = mygcd(p, q);

        // gmp_printf("gcd1 : %Zd\n", gcd);
        // p-1 q-1 过于光滑？
        if(gcd > 100000){
            printf("ERROR\n");
            continue;
        } 

        phi = p*q;

        gcd = mygcd(e, phi);

        // gmp_printf("gcd2 : %Zd\n", gcd);

        if(gcd != 1){
            printf("ERROR\n");
        }else{
            d =  myInvert(e, phi);
            gmp_printf("%Zd\n", d);
        }
    }

    system("pause");
    return 0;
}