class Solution:
    def intersection(self, nums: List[List[int]]) -> List[int]:
        n = len(nums)
        res = []
        dic = defaultdict(int)
        for item in nums:
            for i in item:
                dic[i] += 1

        for k, v in dic.items():
            if v == n:
                res.append(k)

        res.sort()
        return res