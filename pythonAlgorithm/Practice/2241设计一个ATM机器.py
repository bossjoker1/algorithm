class ATM:

    def __init__(self):
        self.cnt = defaultdict(int)
        self.money = [20, 50, 100, 200, 500]

    def deposit(self, banknotesCount: List[int]) -> None:
        for i in range(5):
            self.cnt[self.money[i]] += banknotesCount[i]

    def withdraw(self, amount: int) -> List[int]:
        res = [0, 0, 0, 0, 0]
        for i in range(4, -1, -1):
            k = min(amount // self.money[i], self.cnt[self.money[i]])
            amount -= k * self.money[i]
            res[i] = k

        if amount > 0:
            return [-1]
        for i in range(5):
            self.cnt[self.money[i]] -= res[i]
        return res


# Your ATM object will be instantiated and called as such:
# obj = ATM()
# obj.deposit(banknotesCount)
# param_2 = obj.withdraw(amount)