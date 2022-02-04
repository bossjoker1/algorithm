class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def left_func(nums,target):
            n = len(nums)-1
            left = 0
            right = n
            while(left<=right):
                mid = (left+right)//2
                if nums[mid] >= target:
                    right = mid-1
                if nums[mid] < target:
                    left = mid+1
            return left
        
        a =  left_func(nums,target)
        b = left_func(nums,target+1)
        # 没有的情况
        if  a == len(nums) or nums[a] != target:
            return [-1,-1]
        else:
            return [a,b-1]