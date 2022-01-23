class StockPrice:

    def __init__(self):
        from sortedcontainers import SortedList
        # 用于维护最大值和最小值
        self.sl = SortedList()
        # 维护时间戳和股票价格的映射
        self.d = {}
        # 维护最新时间戳
        self.t = 0

    def update(self, timestamp: int, price: int) -> None:
        if timestamp in self.d:
            self.sl.remove(self.d[timestamp])
        self.d[timestamp] = price
        self.sl.add(price)
        self.t = max(self.t, timestamp)

    def current(self) -> int:
        return self.d[self.t]

    def maximum(self) -> int:
        return self.sl[-1]

    def minimum(self) -> int:
        return self.sl[0]