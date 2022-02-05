class Solution:
    def minimumSum(self, num: int) -> int:
        temp = []
        while num:
            temp.append(int(num%10))
            num //= 10
        
        temp.sort()
        ans1 = int(temp[0] * 10) + temp[2]
        ans2 = int(temp[1] * 10) + temp[3]
        
        return ans1 + ans2