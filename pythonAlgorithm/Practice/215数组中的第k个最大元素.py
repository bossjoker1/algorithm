class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        temp = [0]*20001
        for num in nums:
            temp[num+10000] += 1
        for i in range(len(temp)-1, 0, -1):
            k -= temp[i]
            if k <= 0:
                return i-10000

        return 0