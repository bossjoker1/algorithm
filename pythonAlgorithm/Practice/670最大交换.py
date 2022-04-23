class Solution:
    def maximumSwap(self, num: int) -> int:
        s = str(num)  # int-->str
        List1 = list(s)  #str-->list
        l = len(List1)
        List2 = sorted(List1, reverse = True)  #降序排序
        if List1 == List2:  #排序后的列表与原列表相等就直接返回
            return num
        m = 0
        while m<l and List1[m] == List2[m]:  #找出第一个不相等的位置
            m += 1
        for i in range(l-1, -1, -1):  #逆序遍历
            if List1[i] == List2[m]:
                List1[m], List1[i] = List1[i], List1[m]  #交换位置
                break
        return int(''.join(List1))
