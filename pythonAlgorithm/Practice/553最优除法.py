# 写了半天，写了个dfs求最大值，括号的细节太难搞了
# 一看题解，贪心后面全除就行了
# 给爷整吐了

class Solution:
    def optimalDivision(self, nums: List[int]) -> str:
        if len(nums) == 1:
            return str(nums[0])
        self.maxv = 0.0

        def dfs(nums:List[int]):
            if len(nums) == 2:
                self.maxv = max(self.maxv, nums[0] / nums[1])
            for i in range(len(nums)-1):
                temp = nums[:i]
                temp.append(nums[i] / nums[i+1])
                temp.extend(nums[i+2:])
                dfs(temp)
        dfs(nums)
        print(self.maxv)
        return ""

# 正解，后面全作为分母
class Solution:
    def optimalDivision(self, nums: List[int]) -> str:
        n = len(nums)
        if n == 0: return ""
        if n == 1: return str(nums[0])
        if n == 2: return str(nums[0]) + "/" + str(nums[1])
        res = str(nums[0])
        res += "/(" + str(nums[1])
        for i in range(2, n):
            res += "/" + str(nums[i])
        res += ")"
        return res