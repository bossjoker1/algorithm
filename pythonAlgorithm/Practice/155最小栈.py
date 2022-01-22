class MinStack:

    minval = sys.maxsize

    def __init__(self):
        self.stack = []

    def push(self, val: int) -> None:
        if val < self.minval:
            self.minval = val
        self.stack.append([val, self.minval])

    def pop(self) -> None:
        self.stack.pop()
        if len(self.stack) > 0:
            self.minval = self.stack[-1][1]
        else:
            self.minval = sys.maxsize

    def top(self) -> int:
        return self.stack[-1][0]

    def getMin(self) -> int:
        return self.stack[-1][1]