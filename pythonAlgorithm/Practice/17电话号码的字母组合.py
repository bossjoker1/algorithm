# 模拟题 => dfs，数据小的可怜
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        res = set()
        def Search(s, n):
            if n == len(digits):
                res.add(s)
                return
            if 2 <= int(digits[n]) <= 6:
                for i in range(3):
                    c = chr(ord('a') + 3*(int(digits[n]) - 2) + i)
                    Search(s + c, n+1)
            elif int(digits[n]) == 7:
                for item in ['p', 'q', 'r', 's']:
                    Search(s + item, n+1)
            elif int(digits[n]) == 8:
                for item in ['t', 'u', 'v']:
                    Search(s + item, n+1)
            else:
                for item in ['w', 'x', 'y', 'z']:
                    Search(s + item, n+1)
            
        Search("", 0)

        return list(res)
    
# 评论区nb的python推导式
class Solution:
    def letterCombinations(self, digits: str) -> list:
        KEY = {'2': ['a', 'b', 'c'],
               '3': ['d', 'e', 'f'],
               '4': ['g', 'h', 'i'],
               '5': ['j', 'k', 'l'],
               '6': ['m', 'n', 'o'],
               '7': ['p', 'q', 'r', 's'],
               '8': ['t', 'u', 'v'],
               '9': ['w', 'x', 'y', 'z']}
        if digits == '':
            return []
        ans = ['']
        for num in digits:
            ans = [pre+suf for pre in ans for suf in KEY[num]]
        return ans