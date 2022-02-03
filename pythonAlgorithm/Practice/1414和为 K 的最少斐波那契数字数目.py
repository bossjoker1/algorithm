# 贪心 + 二分查找
class Solution:
    nums = [1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155, 165580141, 267914296, 433494437, 701408733]
    def findMinFibonacciNumbers(self, k: int) -> int:
        if k == 0:
            return 0
        l, r = 0, len(self.nums)-1
        # 二分
        while l < r:
            mid = l + (r - l) // 2 + 1
            if self.nums[mid] > k:
                r = mid - 1
            else:
                l = mid
        return self.findMinFibonacciNumbers(k - self.nums[l]) + 1