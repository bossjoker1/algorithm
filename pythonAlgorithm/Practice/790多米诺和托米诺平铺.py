# 状态递推
# 矩阵快速幂优化
# 轻轻松松！！！

MOD = 10**9 + 7
class Solution:
    def numTilings(self, n: int) -> int:
        t1, t2, t3, t4 = 1, 0, 0, 1
        for i in range(2, n+1):
            h1, h2, h3, h4 = t1, t2, t3, t4
            t1 = h4 % MOD
            t2 = (h1 + h3) % MOD
            t3 = (h1 + h2) % MOD
            t4 = (h1 + h2 + h3 + h4) % MOD
        return t4
    
# #define rep(i,l,r) for(int i=(l);i<=(r);++i)
# #define rpe(i,r,l) for(int i=(r);i>=(l);--i)
 
# inline int max(int x,int y){return x>y?x:y;}

# #define M 1000000007

# typedef long long ll;
# typedef vector<ll> vec;
# typedef vector<vec> mat; // 矩阵

# // 递推式&矩阵快速幂 问题

# // 计算A*B
# mat mul(mat& A, mat& B) {
#     // A (ma * na) B (mb * nb) => C(ma * nb)
#     mat C(A.size(), vec(B[0].size()));
#     for (int i = 0; i < A.size(); i++) {
#         for (int k = 0; k < B.size(); k++) {
#             for (int j = 0; j < B[0].size(); j++) {
#                 C[i][j] += A[i][k] * B[k][j];
#                 C[i][j] %= M;
#             }
#         }
#     }
#     return C;
# }

# // 快速幂计算A^n
# mat pow(mat A, int n) {
#     mat B(A.size(), vec(A.size())); //base
#     for (int i = 0; i < A.size(); i++) {
#         B[i][i] = 1;
#     }
#     while (n > 0) {
#         if (n & 1) B = mul(B, A);
#         A = mul(A, A);
#         n >>= 1;
#     }
#     return B;
# }

# /*-------------------矩阵快速幂模板----------------------------*/

# class Solution {
# public:
#     int numTilings(int n) {
#             // 初始矩阵
#         mat B(4, vec(1));
#         B[0][0] = B[3][0] = 1;
#         B[1][0] = B[2][0] = 0;
#         // 递推矩阵
#         mat A(4,vec(4,0));
#         A[0][3] = A[1][0] = A[1][2] = A[2][0] = A[2][1] = A[3][0] = A[3][1] = A[3][2] = A[3][3] = 1;
#         A = pow(A, n-1);
#         B = mul(A, B);
#         return B[3][0];
#     }
# };


# 作者：bosshhh
# 链接：https://leetcode-cn.com/problems/domino-and-tromino-tiling/solution/python-c-ju-zhen-kuai-su-mi-ji-bai-100-b-izrz/
# 来源：力扣（LeetCode）
# 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。