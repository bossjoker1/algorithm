# 用两个栈，第二个用来逆序
class MyQueue:

    def __init__(self):
        self.stack = []
        self.stack2 = []


    def push(self, x: int) -> None:
        self.stack.append(x)

    def pop(self) -> int:
        while len(self.stack) != 1:
            self.stack2.append(self.stack.pop())
        elem = self.stack.pop()
        while self.stack2:
            self.stack.append(self.stack2.pop())
        return elem

    def peek(self) -> int:
        return self.stack[0]

    def empty(self) -> bool:
        return len(self.stack) == 0


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()