# 直接hash表，空间复杂度为O(n)
class Solution:

    def __init__(self, nums: List[int]):
        self.hash = defaultdict(list)
        for i, v in enumerate(nums):
            self.hash[v].append(i)

    def pick(self, target: int) -> int:
        return random.choice(self.hash[target])


# 水塘抽样，概率论了属于是
class Solution:

    def __init__(self, nums: List[int]):
        self.nums = nums

    def pick(self, target: int) -> int:
        ans = cnt = 0
        for i, v in enumerate(self.nums):
            if v == target:
                cnt += 1
                if randrange(cnt) == 0:
                    ans = i

        return ans