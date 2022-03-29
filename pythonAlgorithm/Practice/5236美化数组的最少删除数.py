class Solution:
    def minDeletion(self, nums: List[int]) -> int:
        n = len(nums)
        res = 0
        # 从左往右
        # 如果遇到i%2==0, 且num[i] == num[i+1]
        # 有两种选择一个是删除num[i]，一个是删除num[i+1]，且必须选择一个
        # 因为两种选择对后面是等价的所以无所谓，属于是sb题了
        # 注意删除后长度不是偶数的话，再在结尾删除一个就行
        
        for i in range(n):
            if (i - res) % 2 == 0 and (i != n-1 and nums[i] == nums[i+1]):
                res += 1

        return res if (n - res) % 2 == 0 else res + 1