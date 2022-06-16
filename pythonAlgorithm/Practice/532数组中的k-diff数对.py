# set去重
# 对每个元素n 判断数组中是否有n + k 或 n - k

class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        visited, res = set(), set()
        for num in nums:
            if num - k in visited:
                res.add(num - k)
            if num + k in visited:
                res.add(num)
            visited.add(num)
        return len(res) 