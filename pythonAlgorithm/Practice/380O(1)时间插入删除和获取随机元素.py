class RandomizedSet:
    def __init__(self):
        self.nums = []
        self.indices = {}

    def insert(self, val: int) -> bool:
        if val in self.indices:
            return False
        self.indices[val] = len(self.nums)
        self.nums.append(val)
        return True

    # 思路是将最后一个元素与被删的元素调换位置
    # 然后pop最后一个元素
    def remove(self, val: int) -> bool:
        if val not in self.indices:
            return False
        id = self.indices[val]
        # 换位
        self.nums[id] = self.nums[-1]
        # 调正idx
        self.indices[self.nums[id]] = id
        self.nums.pop()
        del self.indices[val]
        return True

    def getRandom(self) -> int:
        return choice(self.nums)


