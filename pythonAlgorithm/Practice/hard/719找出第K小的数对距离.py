# 排序 + 二分查找的思路想到了
# 但是没有想到怎么再二分找数目..
# 即一共有两次二分

class Solution:
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        def count(mid: int) -> int:
            cnt = 0
            for j, num in enumerate(nums):
                i = bisect_left(nums, num - mid, 0, j)
                cnt += j - i
            return cnt

        nums.sort()
        return bisect_left(range(nums[-1] - nums[0]), k, key=count)
