# 栈 困难题怎么这么简单..
class Solution:
    def replaceNonCoprimes(self, nums: List[int]) -> List[int]:
        stack = []
        for i in range(len(nums)):
            temp = nums[i]
            while stack:
                g = gcd(stack[-1], temp) 
                if g > 1:
                    temp = temp * stack.pop() // g
                else:
                    break
            stack.append(temp)

        return stack