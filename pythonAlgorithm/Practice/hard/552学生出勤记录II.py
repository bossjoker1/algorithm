# 求可能获得出勤奖励的记录情况数量
# 定义 dp[i][j][k]表示前 i 天有 A 且结尾有连续 k 个 ‘L’ 的可奖励的出勤记录的数量
class Solution:
    def checkRecord(self, n: int) -> int:
        MOD = 10**9 + 7
        # 长度，A 的数量，结尾连续 L 的数量
        dp = [[[0, 0, 0], [0, 0, 0]] for _ in range(n + 1)]
        dp[0][0][0] = 1

        for i in range(1, n + 1):
            # 以 P 结尾的数量
            for j in range(0, 2):
                for k in range(0, 3):
                    dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][k]) % MOD
            
            # 以 A 结尾的数量
            for k in range(0, 3):
                dp[i][1][0] = (dp[i][1][0] + dp[i - 1][0][k]) % MOD
            
            # 以 L 结尾的数量
            for j in range(0, 2):
                for k in range(1, 3):
                    dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % MOD
        
        total = 0
        for j in range(0, 2):
            for k in range(0, 3):
                total += dp[n][j][k]
        
        return total % MOD
