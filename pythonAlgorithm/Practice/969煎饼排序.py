# 感觉挺有意思
# 依次把最大的放到底下，这样翻转上面的就不会影响
# 先把最大的放在最上面，再翻转一次到指定位置
# NP困难问题

class Solution:
    def pancakeSort(self, arr: List[int]) -> List[int]:
        ans = []
        for n in range(len(arr), 1, -1):
            index = 0
            for i in range(n):
                if arr[i] > arr[index]:
                    index = i
            if index == n - 1:
                continue
            m = index
            for i in range((m + 1) // 2):
                arr[i], arr[m - i] = arr[m - i], arr[i]  # 原地反转
            for i in range(n // 2):
                arr[i], arr[n - 1 - i] = arr[n - 1 - i], arr[i]  # 原地反转
            ans.append(index + 1)
            ans.append(n)
        return ans
    
# 根据题意，加速
class Solution:
    def pancakeSort(self, arr: List[int]) -> List[int]:
        ans = []
        for x in range(len(arr), 0, -1):
            idx = arr.index(x)
            ans.extend([idx+1, x])
            arr = arr[:idx:-1] + arr[:idx]

        return ans
