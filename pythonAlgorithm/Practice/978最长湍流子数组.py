# 简单判断就行
class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        n = len(arr)
        res = 1
        cnt = 0
        # 0表示> ; 1表示<; -1表示初始状态
        pre = -1
        for i in range(n):
            if i == 0:
                cnt += 1
            else:
                if arr[i] > arr[i-1] and (pre == 0 or pre == -1):
                    cnt += 1
                    pre = 1
                elif arr[i] < arr[i-1] and (pre == 1 or pre == -1):
                    cnt += 1
                    pre = 0
                else:
                    if arr[i] == arr[i-1]:
                        cnt = 1
                        pre = -1
                    else:
                        cnt = 2
                        pre = 1 if arr[i-1] < arr[i] else 0

            res = max(res, cnt)

        return res
