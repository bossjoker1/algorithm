class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack = []
        for item in asteroids:
            if item > 0:
                stack.append(item)
            while stack and stack[-1] > 0 and item < 0:
                if item + stack[-1] == 0:
                    item = 0
                    stack.pop()
                    continue
                if item + stack[-1] < 0:
                    stack.pop()
                    continue
                if item + stack[-1] > 0:
                    item = 0
                    continue
            if item < 0:
                stack.append(item)

        return stack  