# 当前下标与剩余下标的随机值进行交换
# 思想：洗牌算法

# 即对第一个位置：从[0, n-1]共n个中选一个放入，概率为1/n
# 对第二个位置，从剩下的n-1个选择，则其概率为第一次未选择*第二次选择，(1-1/n)*1/(n-1) = 1/n
# ...

class Solution:

    def __init__(self, nums: List[int]):
        self.nums = nums

    def reset(self) -> List[int]:
        return self.nums

    def shuffle(self) -> List[int]:
        self.temp = list(self.nums)
        n = len(self.nums)
        for i in range(n):
            idx = random.randint(i, n-1)
            self.temp[i], self.temp[idx] = self.temp[idx], self.temp[i]
        return self.temp


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()