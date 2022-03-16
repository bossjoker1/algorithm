# 贪心思想：只要 a + b 的拼接比 b + a更大，则a应该排在b前面

import functools

class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        
        def f(a:int, b:int):
            return int(str(b) + str(a)) - int(str(a) + str(b)) 

        nums.sort(key=functools.cmp_to_key(f))

        # int -> str 是为了防止出现'00'
        return str(int("".join([str(item) for item in nums])))