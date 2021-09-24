// 一开始贪心的角度错了。。搞成贪心地去得到最大的跳跃距离
// 题目是最小的步数

// 正确的贪心思想：维护当前能够到达的最大下标位置，记为边界

class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int max_far = 0;// 目前能跳到的最远位置
        int step = 0;   // 跳跃次数
        int end = 0;    // 上次跳跃可达范围右边界（下次的最右起跳点）
        for (int i = 0; i < nums.size() - 1; i++)
        {
            max_far = std::max(max_far, i + nums[i]);
            // 到达上次跳跃能到达的右边界了
            if (i == end)
            {
                end = max_far;  // 目前能跳到的最远位置变成了下次起跳位置的有边界
                step++;         // 进入下一次跳跃
            }
        }
        return step;
    }
};