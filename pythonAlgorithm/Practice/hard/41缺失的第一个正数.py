# 限制空间复杂度为O(1)，所以不能建立索引数组或者hash表
# 原地hash学到了
# 通过索引建立关系

class Solution:

    # 3 应该放在索引为 2 的地方
    # 4 应该放在索引为 3 的地方

    def firstMissingPositive(self, nums: List[int]) -> int:
        size = len(nums)
        for i in range(size):
            # 先判断这个数字是不是索引，然后判断这个数字是不是放在了正确的地方
            # 这个循环确保
            while 1 <= nums[i] <= size and nums[i] != nums[nums[i] - 1]:
                # 注意python同时赋值有顺序
                nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]

        for i in range(size):
            if i + 1 != nums[i]:
                return i + 1

        return size + 1
