class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        n, m = len(s), len(goal)
        if n != m:
            return False
        for i in range(n):
            tempStr = s[i:] + s[:i]
            # print(tempStr)
            if tempStr == goal:
                return True

        return False
