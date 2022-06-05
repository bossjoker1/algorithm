# 概率论忘光了

import random
import math
class Solution(object):
    def __init__(self, radius, x_center, y_center):
        self.radius = radius
        self.x = x_center
        self.y = y_center
    def randPoint(self):
        r = (random.random() ** 0.5) * self.radius
        theta = random.uniform(0, 2 * math.pi)
        return [r * math.cos(theta) + self.x, r * math.sin(theta) + self.y]

# Your Solution object will be instantiated and called as such:
# obj = Solution(radius, x_center, y_center)
# param_1 = obj.randPoint()