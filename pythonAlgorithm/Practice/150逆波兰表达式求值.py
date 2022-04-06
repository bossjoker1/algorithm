# 经典题
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        # priority = {'+':1, '-':1, '*':2, '/':2}
        # nums, operate = [], []
        nums = []
        for item in tokens:
            if item not in ['-', '+', '*', '/']:
                nums.append(int(item))
            else:
                # print(nums)
                a2, a1 = nums.pop(), nums.pop()
                if item == '+':
                    a1 = a1+a2
                elif item == '-':
                    a1 = a1 - a2
                elif item == '*':
                    a1 = a1 * a2
                else:
                    a1 = int(a1/a2)
                nums.append(a1)

        return nums[-1]