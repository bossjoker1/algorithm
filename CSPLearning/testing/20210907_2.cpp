#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat; // 矩阵

const int M = 2021;

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
    ll n;
    cin >> n;
    if (n == 1) {
        cout << 1;
    }
    else {
        // 3*3 f(n) = f(n-3)+f(n-2)+f(n-1)
        mat A(3, vec(3)), B(3, vec(1));
        A[0][0] = A[0][1] = A[0][2] = A[1][0] = A[2][1] =  1;
        B[0][0] = 2, B[1][0] = 1, B[2][0] = 1;
        A = pow(A, n-1);
        /*for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[0].size(); j++) {
                cout << A[i][j];
            }
            cout << endl;
        }*/
        A = mul(A, B);
        cout << A[1][0];
    }

    return 0;
}