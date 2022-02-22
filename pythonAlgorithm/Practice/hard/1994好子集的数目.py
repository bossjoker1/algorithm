# 解题关键：数字大小≤30
# 将30个数字分为3类
class Solution:
    def numberOfGoodSubsets(self, nums: List[int]) -> int:
        # 返回列表中所有元素的计数hash
        cnt=Counter(nums)
        mod=10**9+7
        # 30以内质数：[2,3,5,7,11,13,17,19,23,29]
        prime=[2,3,5,7,11,13,17,19,23,29]
        forbid = [4,8,9,12,16,18,20,24,25,27,28]
        m=len(prime)
        dp=[0]*(1<<m)
        dp[0]=1
        for num in cnt:
            if num==1:continue
            if num in forbid:
                continue
            mask=0
            for i in range(m):
                if num%prime[i]==0:
                    mask |= 1<<i
            for i in range(1<<m):
                if i&mask==0:
                    dp[i|mask]+=dp[i]*cnt[num]
                    dp[i|mask]%=mod
        # 只有一个1不行需减去
        # 但是1可以增加选择
        return (1<<cnt[1])*(sum(dp)-1)%mod