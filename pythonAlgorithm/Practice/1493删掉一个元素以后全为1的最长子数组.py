# 先把0的位置找出来
# 设置哨兵便于处理 => 不需要管边界情况
# 但俺的空间复杂度为O(n)
class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        # 滑动窗口的边界为0
        l,r = 0, 0
        res = 0
        zeros = [-1]
        for i in range(n):
            if nums[i] == 0:
                zeros.append(i)

        if len(zeros) == 1:
            return n - 1

        zeros.append(n)
        # print(zeros)
        for i in range(1, len(zeros)-1):
            res = max(res, zeros[i+1] - zeros[i-1] - 2)
                
        return res

# 滑动窗口做法
# 明显空间复杂度为常数级别但是leetcode上跑还不如我自己上面的做法?!!
class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        # 滑动窗口的边界为0
        # 窗口中0的个数
        l,r,count= 0, 0, 0 
        res = 0

        while r < n:
            if nums[r] == 0:
                count += 1

            while count > 1:
                # 窗口收缩：
                if nums[l] == 0:
                    count -= 1
                l += 1
            
            res = max(res, r - l + 1)
            r += 1

        return res-1