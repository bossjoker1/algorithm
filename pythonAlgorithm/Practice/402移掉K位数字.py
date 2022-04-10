class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        # 单调栈
        # 遇到栈中比自己大的，就删除，此时当前值所构成的数必然更小
        stack = []
        remain = len(num) - k
        for digit in num:
            while k and stack and stack[-1] > digit:
                stack.pop()
                k -= 1
            stack.append(digit)
        
        # lstrip()删除左边的指定元素
        # 直接截取前面的就行，没用完的k用于去除尾项
        return ''.join(stack[:remain]).lstrip('0') or '0'