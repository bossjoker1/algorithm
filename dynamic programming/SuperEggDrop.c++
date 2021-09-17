/*
非常经典的高楼扔鸡蛋问题
一种思路是dp[k][n]表示k个鸡蛋，n层楼
状态转移方程是 dp[k,n] = min(1≤i≤K)(max (dp[k-1][i-1],dp[k][N-i])+1)
hard难度，但其实理解题意，选用最恰当的转移方程，代码量很少
dp[k][m]=n : 表示k个鸡蛋,可以扔m次，最坏情况下可以测量一栋n层的楼
则最后求得就是dp[K][m] == N 时，m的值，与题目意思完美契合
状态转移方程： do[k][m] = dp[k][m-1](鸡蛋没碎，即楼上的层数) + dp[k-1][m-1](鸡蛋碎了，楼下的层数) + 1(当前这一层)
时间空间复杂度O(K*N)
大佬提到，这题层数是随扔次数线性增加的，可以用二分搜索的思想进行剪枝
*/
class Solution {
public:
    int superEggDrop(int K, int N) {
        //创建二维数组，初始化为0
        vector<vector<int>> dp(K+1, vector(N+1,0));
        int m = 0;//从 0开始
        while(dp[K][m] < N){
            m++;
            for(int k = 1;k <= K; k++)
                dp[k][m] = dp[k][m-1] + dp[k-1][m-1] + 1;
        }
        return m;
    }
};