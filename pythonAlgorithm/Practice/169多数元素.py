# 什么摩尔投票法，拼消耗，名字倒挺高大上...
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        major = 0
        count = 0
        
        for n in nums:
            if count == 0:
                major = n
            if n == major:
                count = count + 1
            else:
                count = count - 1

        return major
