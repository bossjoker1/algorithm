//698，把数组划分为k个相等的子集，题目读起来简单，
//做起来无从下手，只能抄别人的作业了，真的强！！！
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        // 计算和，得到每组的预计和
        int maxNum = INT_MIN;
        int n = nums.size();
        int total = 0;
        for (int i = 0; i < n; ++i)
        {
            total += nums[i];
            maxNum = max(maxNum, nums[i]);
        }
        // 预先判断来优化
        int target = total / k;
        if ((total % k != 0) || (target < maxNum)) //平均值比最大值还小也不行
        {
            return false;
        }
        bool* used = new bool[n];
        memset(used, 0, sizeof(bool) * n);
        return dfs(nums, target, target, k, 0, used);
    }

    // target 目标值
    // rest 剩余的数字
    // group 当前组的编号，是 1-k 共k组
    // start 开始遍历nums的序号， 0~n-1
    // used 数组标记
    bool dfs(vector<int>& nums, int target, int rest, int group, int start, bool* used)
    {
        // 如果移到最后一个组则表示成功了
        if (group == 0)
        {
            return true;
        }
        // 遍历数字取那些没被用过的数字
        int n = nums.size();
        for (int i = start; i < n; ++i)
        {
            if (!used[i])
            {
                used[i] = true;
                // 考虑两种情况
                // - 当前数字考虑后依然小于目标，则在当前组内递归(减少目标值，起始位置+1)
                // - 当前数字考虑后依然等于目标，则继续遍历下一组(重置目标和起始位置)
                if ((nums[i] < rest && dfs(nums, target, rest-nums[i], group, i+1, used))
                        || (nums[i] == rest && dfs(nums, target, target, group-1, 0, used)))
                {
                    return true;
                }
                // 遍历完回溯设置回去，撤销选择
                used[i] = false;
            }
        }
        return false;
    }
};
