# hard 这次周赛唯一能看的题
# 最大数据为15
# 感觉dfs也不会爆栈

# 直接穷举...

class Solution:
    def maximumGood(self, statements: List[List[int]]) -> int:
        ans, n = 0, len(statements)
        for mask in range(1, 1<<n):
            cnt = 0
            flag = True
            for i in range(n):
                if not flag: break
                if (mask>>i) & 1:
                    for j in range(n):
                         if statements[i][j] < 2 and ((mask >> j) & 1) != statements[i][j]:
                             flag = False
                             break
                    cnt += 1  
            
            if flag: ans = max(ans, cnt)

        return ans

class Solution:
    def maximumGood(self, statements: List[List[int]]) -> int:
        def check(i: int) -> int:
            cnt = 0  # i 中好人个数
            for j, row in enumerate(statements):  # 枚举 i 中的好人 j
                if (i >> j) & 1:
                    if any(st < 2 and st != (i >> k) & 1 for k, st in enumerate(row)):
                        return 0  # 好人 j 的某个陈述 st 与实际情况矛盾
                    cnt += 1
            return cnt

        return max(check(i) for i in range(1, 1 << len(statements)))

# class Solution {
# public:
#     int maximumGood(vector<vector<int>>& statements) {
#         int n = statements.size(), ans = 0;
#         for (int mask = 0; mask < (1 << n); ++mask) {
#             bool flag = true;
#             for (int i = 0; i < n; ++i)
#                 if ((mask >> i) & 1) {
#                     for (int j = 0; j < n; ++j) {
#                         if (statements[i][j] == 2) continue;
#                         int real_j = ((mask >> j) & 1);
#                         if (real_j != statements[i][j]) {
#                             flag = false;
#                             break;
#                         }
#                     }
#                 }
#             if (flag) ans = max(ans, __builtin_popcount(mask));
#         }
#         return ans;
#     }
# };