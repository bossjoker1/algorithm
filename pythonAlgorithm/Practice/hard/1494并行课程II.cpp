// 真难
class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<int> prerequisite(n, 0);
        for (const auto& pair : relations) {
            int pre = pair[0] - 1;
            int after = pair[1] - 1;
            // 举例：prerequisite[1] = 0110 表示1的先修课为2和3
            prerequisite[after] |= 1<<pre;
        }

        int totalState = 1 << n;
        vector<int> dp(totalState, 16);
        // 0为不需要上任何课的状态，因此不需要学期
        dp[0] = 0;

        vector<int> cnt(totalState);
        cnt[0] = 0;
        // 小技巧，计算每个数字的二进制数中，1的个数
        for (int i = 1; i < totalState; ++i) {
            cnt[i] = cnt[i>>1] + (i&1);
        }

        // taken表示已经上过的课，假设taken = 0111，表示课程1 2 3已经上过了
        for (int taken = 0; taken < totalState; ++taken) {
            if (dp[taken] > n) continue;
            int cur = 0;
            // 在上过taken的基础上，还有哪些课可以上，要满足两个条件
            // 1. ((taken & (1 << j)) == 0) 表示这个课在taken中没上过
            // 2. ((prerequisite[j] & taken) == prerequisite[j]) 表示这个课的先修课已经上完了
            for (int j = 0; j < n; ++j) {
                if (((taken & (1 << j)) == 0) && ((prerequisite[j] & taken) == prerequisite[j])) {
                    // 存这学期可以上的课，注意，可以上不代表一定要上，也不一定要上满，这题的本质是NPC问题，任何贪心的思想都是错的，选择cur中的课来上的这个操作，用下面枚举子集的方法实现
                    cur |= (1 << j);
                }
            }
            // 枚举cur的子集，比如cur = 111，它的子mask集合就是{111, 110, 101 011, 100, 010, 001}
            for (int subMask = cur; subMask != 0; subMask = subMask-1 & cur) {
                // 这学期上的课的数量不能超过k
                if (cnt[subMask] <= k) {
                    // 之前上完taken，这学期再上subMask，看看会不会更好
                    dp[taken|subMask] = min(dp[taken|subMask], dp[taken] + 1);
                }
            }
        }
        
        return dp[totalState - 1];
    }
};

