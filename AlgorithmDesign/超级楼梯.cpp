#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

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
            }
        }
    }
    return C;
}

// 快速幂计算A^n
mat pow(mat A, ll n) {
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


int main() {
    int n, M;
    scanf("%d",&n);
    mat B(2, vec(1));
    B[0][0] = 1, B[1][0] = 1;
    for(int i = 0; i < n; i++){
        mat A(2, vec(2));
        A[0][0] = A[0][1] = A[1][0] =  1;
        scanf("%d",&M);
        if(M == 1){
            printf("0\n");
            continue;
        }
        A = pow(A, M-2);
        // for (int i = 0; i < A.size(); i++) {
        //     for (int j = 0; j < A[0].size(); j++) {
        //         cout << A[i][j];
        //     }
        //     cout << endl;
        // }
        A = mul(A, B);
        printf("%d\n", A[0][0]);
    }
    return 0;
}