class DetectSquares:

    def __init__(self):
        self.points = defaultdict(int)        

    def add(self, point: List[int]) -> None:
        self.points[ (point[0], point[1]) ] += 1

    def count(self, point: List[int]) -> int:
        res = 0
        x,  y = point

        for p, v in self.points.items():
            if p[0] == x or p[1] == y:
                continue
            if abs(p[0] - x) != abs(p[1] - y):
                continue
            p0, p1 = (p[0], y), (x, p[1])
            # get如果没有会返回noneType而无法参与整数运算，此时可以再接一个参数表示没有情况下的默认值
            res += self.points.get(p0, 0) * self.points.get(p1, 0) * v

        return res 

# Your DetectSquares object will be instantiated and called as such:
# obj = DetectSquares()
# obj.add(point)
# param_2 = obj.count(point)