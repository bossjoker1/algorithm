#include <string.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)
 
inline int max(int x,int y){return x>y?x:y;}
 
inline int read(){
    int x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}

#define M 997

typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat; // 矩阵

// 递推式&矩阵快速幂 问题

// 计算A*B
mat mul(mat& A, mat& B) {
    // A (ma * na) B (mb * nb) => C(ma * nb)
    mat C(A.size(), vec(B[0].size()));
    for (int i = 0; i < A.size(); i++) {
        for (int k = 0; k < B.size(); k++) {
            for (int j = 0; j < B[0].size(); j++) {
                C[i][j] += A[i][k] * B[k][j];
                C[i][j] %= M;
            }
        }
    }
    return C;
}

// 快速幂计算A^n
mat pow(mat A, int n) {
    mat B(A.size(), vec(A.size())); //base
    for (int i = 0; i < A.size(); i++) {
        B[i][i] = 1;
    }
    while (n > 0) {
        if (n & 1) B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}

int main(){

    int col = read();

    // 初始矩阵
    mat B(6, vec(1));
    B[0][0] = B[2][0] = B[3][0] = B[4][0] = B[5][0] = 1;
    B[1][0] = 0;
    // 递推矩阵
    mat A(6,vec(6));
    A[0][0] = A[0][2] = A[0][3] = A[0][4] = A[0][5] = 1;
    A[1][2] = 1;
    A[2][0] = A[2][1] = 1;
    A[3][0] = A[3][4] = 1;
    A[4][0] = A[4][3] = 1;
    A[5][0] = 1;

    A = pow(A, col-1);

    B = mul(A, B);

    printf("%d\n", B[0][0]);

    return 0;
}