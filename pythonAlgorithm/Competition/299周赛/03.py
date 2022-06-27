# 转化为最大子数组和
# 应该算不了hard题
class Solution:
    def maximumsSplicedArray(self, nums1: List[int], nums2: List[int]) -> int:
        def getMaxSubSum(nums1, nums2):
            maxSum = -inf
            tempSum = 0
            n = len(nums1)
            k = 0
            for i in range(n):
                tempSum += nums1[i] - nums2[i]
                while tempSum < 0 and  k <= i:
                    tempSum -= nums1[k] - nums2[k]
                    k += 1
                if tempSum > maxSum:
                    maxSum = tempSum

            return sum(nums2) + maxSum

        return max(getMaxSubSum(nums1, nums2), getMaxSubSum(nums2, nums1))

# 简化，不用左指针
class Solution:
    def maximumsSplicedArray(self, nums1: List[int], nums2: List[int]) -> int:
        def getMaxSubSum(nums1, nums2):
            maxSum = -inf
            tempSum = 0
            for i in range(len(nums1)):
                tempSum = max(tempSum + nums2[i] - nums1[i], 0)
                maxSum = max(maxSum, tempSum)

            return sum(nums1) + maxSum

        return max(getMaxSubSum(nums1, nums2), getMaxSubSum(nums2, nums1))