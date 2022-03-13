class Solution:
    def maximumTop(self, nums: List[int], k: int) -> int:
        n = len(nums)
        # n = 0  
        # n=1, k为奇数个时会拿空
        if n == 0 or (n==1 and k % 2 == 1):
            return -1
        # sb
        if k == 0:
            return nums[0]
        # 只能是第二个
        if n > 1 and k == 1:
            return nums[1]
        # 可以拿完后摆个大的
        # 多的先摆小的后摆大的
        if k > n:
            return max(nums)
        # 只能取前面的，不可能取完
        elif k == n:
            return max(nums[:k-1])
        # 取完后和前面的比
        else:
            return max(max(nums[:k-1]), nums[k])
        