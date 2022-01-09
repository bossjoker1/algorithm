class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        
        n=len(nums)
        res=[]
        # 特判
        if(not nums or n<3):
            return []
        nums.sort()
        res=[]
        for i in range(n):
            # 全为正整数的情况
            if(nums[i]>0):
                return res
            # 冗余情况，加速
            if(i>0 and nums[i]==nums[i-1]):
                continue
            # 定位i，L, R滑动。
            L=i+1
            R=n-1
            while(L<R):
                sum  = nums[i]+nums[L]+nums[R]
                if(sum==0):
                    res.append([nums[i],nums[L],nums[R]])
                    # 去重
                    while(L<R and nums[L]==nums[L+1]):
                        L=L+1
                    while(L<R and nums[R]==nums[R-1]):
                        R=R-1
                    L=L+1
                    R=R-1
                elif(sum>0):
                    R=R-1
                else:
                    L=L+1
        return res
