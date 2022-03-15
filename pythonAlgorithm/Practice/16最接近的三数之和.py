# 三个点，定左边，右边才能双指针移动
# O(n^2)的时间复杂度
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        n = len(nums)
        ans = nums[0] + nums[1]+ nums[2]
        for i in range(n-2):
            l = i+1
            r = n - 1
            while l < r:
                temps = nums[i] + nums[l] + nums[r]
                if abs(temps - target) < abs(ans - target):
                    ans = temps
                if temps == target:
                    return target
                elif temps < target:
                    l += 1
                else:
                    r -= 1

        return ans
